# Sonect SDK for iOS [PRELIMINARY]

In this document we will go through the necessary steps to integrate
Sonect SDK in your iOS app. 

## Installation: 

Via dependency managers:
- Cocoapods: `pod 'sonect-sdk-ios'`
- Carthage: `github "sonect/sonect-sdk-ios"`
- Manual

Sonect SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

Minimum version: iOS 10.0+ 

The main entry point to the SDK is `SNCSonect` object. To present the Sonect view controller, you have to obtain the SDK token, the user ID and the signature, which **must** be calculated on your bank's serverside for security reasons.  

## Obj-C

### Simple SDK Integration 
```
SNCCredentials *credentials = [[SNCCredentials alloc] initWithSdkToken:_SDK_TOKEN_
                                                                userId:_BANK_USER_ID_
                                                             signature:_BANK_SIGNATURE_];

//Create a SonectConfiguration.plist, alternatively use initWithContentsOfFile:
SNCConfiguration *configuration = [SNCConfiguration defaultConfiguration];

[SNCSonect presentWithCredentials:credentials
                    configuration:configuration
         presentingViewController:self.viewController];
```

### Configuration file

In order to configure the SDK, create a `SonectConfiguration.plist` file, and fill out the mandatory fields. You can load the configuration by using the `SNCConfiguration` object. A sample plist file might look like this, for more info consult the `SNCConfiguration` interface documentation. 

Sample `SonectConfiguration.plist` values: 
```
<dict>
	<key>SonectAlpha2CountryCode</key>
	<string>ch</string>
	<key>SonectCurrency</key>
	<string>CHF</string>
	<key>SonectDefaultWithdrawAmountIndex</key>
	<integer>2</integer>
	<key>SonectAllowedCountryCodes</key>
	<array>
		<integer>41</integer>
		<integer>1</integer>
	</array>
</dict>
```

### Payment Processing

In order to show available payment methods with your bank’s preferred details like name, details and logo, you should assign an object that implements `SNCSonectPaymentDataSource` to the `SNCSonect.paymentDataSource`. 

You must then implement the following method in your class implementing `SNCSonectPaymentDataSource`
```
- (void)sonect:(SNCSonect *)sonect loadAvailablePaymentMethodsForContext:(SNCPaymentContext)context 
       handler:(SNCPaymentMethodsHandler)handler
```

and return an array of objects that implement `SNCPaymentMethod` protocol, which will represent the available payment methods from your bank, i.e. different accounts. 

In order to check if your bank can authorize a certain amount to be paid, the object implementing `SNCPaymentMethod` protocol will have to implement 

```
- (void)canPayAmount:(SNCTransactionAmount *)amount 
         withHandler:(SNCPaymentMethodAvailabilityHandler)paymentAvailabilityHandler
``` 

check for the account balance, and then return the permission to proceed with payment, or an error if one occured while checking for the balance. 

In order to process the payment, your object implementing `SNCPaymentMethod` protocol will need to create an `SNCTransactionMetadata` object and pass it back to the SDK for processing. The SDK will call `-payAmount:withHandler:` for you, and you will pass back the necessary info via `SNCPaymentMethodHandler`, this can happen asynchronously. 

If your bank supports Open Bank API-s, the transaction will be fully processed by the SDK. However, if your bank doesn’t support the Open Bank API-s, you should process the transaction, and pass the payment reference in the `SNCBankTransactionMetadata` object. The transactionMetadata object should then be passed back to the SDK via the `SNCPaymentMethodHandler` callback.

```
- (void)payAmount:(SNCTransactionAmount *)amount 
     withHandler:(SNCPaymentMethodHandler)handler {
    //Obtain a payment reference by resolving the payment on your server. This can happen asynchronously
    NSString *paymentReference = @"_YOUR_PAYMENT_REFERENCE_";

    //Create a transactionMetadata object by passing the amount and the payment reference
    SNCBankTransactionMetadata *transactionMetadata = [SNCBankTransactionMetadata transactionMetadataWithAmount:amount paymentReference:paymentReference];

    //Passing the transaction metadata back to SDK will start the payment resolution on Sonect and show a successful transaction with a barcode. 
    handler(transactionMetadata, nil, SNCPaymentStatusPending); 
}
```

### Themes

Sonect SDK supports theming colors and fonts to allow you to customize the SDK, so that it looks and feels right when embedded in your app. To apply a theme, you need to create a new `SNCTheme` object and apply a theme like in the following example. 

```
SNCTheme *theme = [SNCTheme new];
theme.type = SNCThemeTypeLight;
theme.fontName = "Futura-Medium";
theme.boldFontName = "Futura-CondensedExtraBold";
theme.detailColor1 = UIColor.yellowColor;
theme.detailColor2 = UIColor.yellowColor;
theme.detailColor3 = UIColor.yellowColor;
theme.detailColor4 = UIColor.yellowColor;
theme.detailColor5 = UIColor.yellowColor;
theme.navigationBarTintColor = UIColor.yellowColor;
theme.navigationBarTitleImage = [UIImage imageNamed:@"rba"];
[theme set];
```

Following are samples of dark and light theme with different detail color and font settings, as displayed on the Withdraw function inside Sonect SDK. 

![theme_samples.png](/theme_samples.png)
