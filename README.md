# Sonect SDK for iOS [PRELIMINARY]

In this document we will go through the necessary steps to integrate
Sonect SDK in your iOS app. 

## Installation: 

Via dependency managers:
- Cocoapods 
- Carthage
- Manual

Email Sonect to obtain your SDK token.

Sonect SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

The main entry point to the SDK is `SNCSonect` object. To present the Sonect view controller, do the following

## Obj-C

### Simple SDK Integration 
```
SNCCredentials *credentials = [[SNCCredentials alloc] initWithSdkToken:_SDK_TOKEN_
                                                                userId:_BANK_USER_ID_
                                                             signature:_BANK_SIGNATURE_];

SNCConfiguration *configuration = [[SNCConfiguration alloc] initWithAlpha2CountryCode:@"CH"
                                                                             currency:@"CHF"
                                                                  allowedCountryCodes:@[@41]];

[SNCSonect presentWithCredentials:credentials
                    configuration:configuration
         presentingViewController:self.viewController];
```

### Payment Processing: 

In order to show available payment methods with your bank’s preferred details like name, details and logo, you should assign an object that implements `SNCSonectPaymentDataSource` to the `SNCSonect.paymentDataSource`. 

You must then implement the following method in your class implementing `SNCSonectPaymentDataSource`
```
- (void)sonect:(SNCSonect *)sonect loadAvailablePaymentMethodsForContext:(SNCPaymentContext)context 
       handler:(SNCPaymentMethodsHandler)handler
```

and return an array of objects that implement `SNCPaymentMethod` protocol, which will represent the available payment methods from your bank, i.e. different accounts. 

In order to check if your bank can authorize a certain amount to be paid, the object implementing `SNCPaymentMethod` protocol will have to implement 

`- (void)canPayAmount:(SNCTransactionAmount *)amount 
          withHandler:(SNCPaymentMethodAvailabilityHandler)paymentAvailabilityHandler
` 

check for the account balance, and then return the permission to proceed with payment, or an error if one occured while checking for the balance. 

In order to process the payment, your object implementing `SNCPaymentMethod` protocol will need to create an `SNCTransactionMetadata` object and pass it back to the SDK for processing. The SDK will call `-payAmount:withHandler:` for you, and you will pass back the necessary info via `SNCPaymentMethodHandler`. This can happen asynchronously. 

```
-(void)payAmount:(SNCTransactionAmount *)amount 
     withHandler:(SNCPaymentMethodHandler)handler;
```

If your bank supports Open Bank API-s, the transaction will be fully processed by the SDK. However, is your bank doesn’t support the Open Bank API-s, you should process the transaction, and pass the payment reference in the `SNCTransactionMetadata` object. The `transactionMetadata` object should then be passed back to the SDK via the `SNCPaymentMethodHandler` callback. 

```
@implementation SNCBankTransactionMetadata

- (NSDictionary <SNCTransactionMetadataKey, NSString *> *)serialized {
    return @{
             SNCTransactionMetadataKeyCurrency: @"CHF",
             SNCTransactionMetadataKeyAmount: @"20",
             SNCTransactionMetadataPaymentReference: @"YOUR_BANK_PAYMENT_REFERENCE"
             };
}

@end
```
