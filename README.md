# Sonect SDK for iOS

In this document we will go through the necessary steps to integrate
Sonect SDK in your iOS app. 

Contact support@sonect.ch if additional info is needed.

## Installation: 

Via dependency managers:
- Cocoapods: `pod 'sonect-sdk-ios'`
- Carthage: `github "sonect/sonect-sdk-ios"`
- Manual

Sonect SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

Minimum version: iOS 9.0+ 

The main entry point to the SDK is `SNCSonect` object. To present the Sonect view controller, you have to obtain the SDK token, the user ID and the signature, which **must** be calculated on your bank's serverside for security reasons.  

## Simple SDK Integration 

### Obj-C
```objc
SNCCredentials *credentials = [[SNCCredentials alloc] initWithSdkToken:_SDK_TOKEN_
                                                                userId:_BANK_USER_ID_
                                                             signature:_BANK_SIGNATURE_];

//Create a SonectConfiguration.plist, alternatively use initWithContentsOfFile:
SNCConfiguration *configuration = [SNCConfiguration defaultConfiguration];

[SNCSonect presentWithCredentials:credentials
                    configuration:configuration
         presentingViewController:self.viewController];
```
### Swift
```swift
let credentials = SNCCredentials(sdkToken: _SDK_TOKEN_,
                 	           userId: _BANK_USER_ID_,
                                signature: _BANK_SIGNATURE_)

let configuration = SNCConfiguration.default()

SNCSonect.present(with: credentials,
         configuration: configuration,
            presenting: self)
```

## Configuration file

In order to configure the SDK, create a `SonectConfiguration.plist` file, and fill out the mandatory fields. You can load the configuration by using the `SNCConfiguration` object. A sample plist file might look like this, for more info consult the `SNCConfiguration` interface documentation. 
Note that "My App Name" contains special non-breaking space rather than regular one, for the App title always to appear on the single line.

Sample `SonectConfiguration.plist` values: 
```xml
<dict>
	<key>SonectDashboardWelcomeName</key>
	<string>My App Name</string>
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
	<key>SonectTransactionStatusToPaymentReferenceVisibility</key>
	<dict>
		<key>expired</key>
		<false/>
		<key>cancelled</key>
		<false/>
		<key>rejected</key>
		<true/>
		<key>confirmed</key>
		<true/>
	</dict>
</dict>
```

## Payment Processing

In order to show available payment methods with your bank’s preferred details like name, details and logo, you should assign an object that implements `SNCSonectPaymentDataSource` to the `SNCSonect.paymentDataSource`. 

You must then implement the following method in your class implementing `SNCSonectPaymentDataSource`
### Obj-C
```objc
- (void)sonect:(SNCSonect *)sonect loadAvailablePaymentMethodsForContext:(SNCPaymentContext)context 
       handler:(SNCPaymentMethodsHandler)handler
```
### Swift
```swift
func sonect(_ sonect: Sonect, loadAvailablePaymentMethodsFor context: PaymentContext, handler: @escaping PaymentMethodsHandler)
```

and return an array of objects that implement `SNCPaymentMethod` protocol, which will represent the available payment methods from your bank, i.e. different accounts. 

In order to check if your bank can authorize a certain amount to be paid, the object implementing `SNCPaymentMethod` protocol will have to implement 
### Obj-C
```objc
- (void)canPayAmount:(SNCTransactionAmount *)amount 
         withHandler:(SNCPaymentMethodAvailabilityHandler)paymentAvailabilityHandler
``` 
### Swift
```swift
func canPayAmount(_ amount: SNCTransactionAmount, handler: @escaping SNCPaymentMethodAvailabilityHandler)handler
```
check for the account balance, and then return the permission to proceed with payment, or an error if one occured while checking for the balance. The error alert will display info from the `userInfo` dictionary that you pass in the `NSError` object. To change the title of the alert, populate `SNCLocalizedTitleKey`, to change the description, populate `NSLocalizedDescriptionKey`. 

In order to process the payment, your object implementing `SNCPaymentMethod` protocol will need to create an `SNCTransactionMetadata` object and pass it back to the SDK for processing. The SDK will call `-payAmount:withHandler:` for you, and you will pass back the necessary info via `SNCPaymentMethodHandler`, this can happen asynchronously. 

If your bank supports Open Bank API-s, the transaction will be fully processed by the SDK. However, if your bank doesn’t support the Open Bank API-s, you should process the transaction, and pass the payment reference in the `SNCBankTransactionMetadata` object. The transactionMetadata object should then be passed back to the SDK via the `SNCPaymentMethodHandler` callback.
### Obj-C
```objc
- (void)payAmount:(SNCTransactionAmount *)amount 
     withHandler:(SNCPaymentMethodHandler)handler {
    //Obtain a payment reference by resolving the payment on your server. This can happen asynchronously
    NSString *paymentReference = @"_YOUR_PAYMENT_REFERENCE_";
    NSString *signature = @"_YOUR_SIGNATURE_";

    //Create a transactionMetadata object by passing the amount and the payment reference
    SNCBankTransactionMetadata *transactionMetadata = [SNCBankTransactionMetadata transactionMetadataWithAmount:amount paymentReference:paymentReference signature:signature];

    //Passing the transaction metadata back to SDK will start the payment resolution on Sonect and show a successful transaction with a barcode. 
    handler(transactionMetadata, nil, SNCPaymentStatusPending); 
}
```
### Swift
```swift
func payAmount(_ amount: SNCTransactionAmount, handler: @escaping SNCPaymentMethodHandler)  {
    // Obtain a payment reference by resolving the payment on your server. This can happen asynchronously
    let paymentReference = "_YOUR_PAYMENT_REFERENCE_"
    let signature = "_YOUR_SIGNATURE_"

    // Create a transactionMetadata object by passing the amount and the payment reference
    let transactionMetadata = SNCBankTransactionMetadata(amount: amount, paymentReference: paymentReference, signature: signature)

    // Passing the transaction metadata back to SDK will start the payment resolution on Sonect and show a successful transaction with a barcode. 
    handler(transactionMetadata, nil, SNCPaymentStatus.pending)
}
```
## Themes

Sonect SDK supports theming colors and fonts to allow you to customize the SDK, so that it looks and feels right when embedded in your app. To apply a theme, you need to create a new `SNCTheme` object and apply a theme like in the following example. 
### Obj-C
```objc
SNCTheme *theme = [SNCTheme new];
theme.type = SNCThemeTypeLight;
theme.fontName = @"Futura-Medium";
theme.boldFontName = @"Futura-CondensedExtraBold";
theme.primaryColor1 = UIColor.yellowColor;
theme.primaryColor2 = UIColor.yellowColor;
theme.primaryColor3 = UIColor.yellowColor;
theme5.statusTextColor1 = UIColor.redColor;
[theme set];
```
### Swift
```swift
let theme = SNCTheme()
theme.type = .light
theme.fontName = "Futura-Medium”
theme.boldFontName = "Futura-CondensedExtraBold"
theme.primaryColor1 = .yellow
theme.primaryColor2 = .yellow
theme.primaryColor3 = .yellow
theme.statusTextColor1 = .red
theme.set()
```
Following are samples of dark and light theme with different detail color and font settings, as displayed on the Dashboard inside Sonect SDK. 

![theme_samples.png](/theme_samples.png)
