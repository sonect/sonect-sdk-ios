# Sonect SDK for iOS

In this document we will go through the necessary steps to integrate
Sonect SDK in your iOS app. 

## Installation: 

Via dependency managers:
- Cocoapods, Carthage TBA. 

Email Sonect to obtain your API_KEY

Sonect SDK is written from ground up in Objective - C, and doesn’t have any external dependencies, so that it plays well with older code bases. 

The main entry point to the SDK is `SNCSonect` object. To present the Sonect view controller, do the following

## Obj-C

### Simple SDK Integration 
```
SNCToken *token = [SNCToken tokenWithValue:@“YOUR_TOKEN_HERE”];
SNCConfiguration *configuration = [SNCConfiguration configurationWithToken:token theme:nil];
SNCSonectViewController *viewController = [SNCSonect makeViewControllerWithConfiguration:configuration paymentDataSource:self]; 

//present view controller 
```

### Payment Processing: 

In order to show available payment methods with your bank’s logo, you should implement the method on your class that implements `SNCSonectPaymentDataSource`, and return an array of object that implement `SNCPaymentMethod` protocol. 

```
- (void)sonect:(SNCSonect *)sonect loadAvailablePaymentMethodsWithHandler:(SNCPaymentMethodsHandler)handler;
```

In order to process the payment, your object implementing `SNCPaymentMethod` will need to create an `SNCTransactionMetadata` object and pass it back to the SDK for processing. The SDK will call `-payAmount:withHandler:` for you, and you will pass back the necessary info via `SNCPaymentMethodHandler`. This can happen asynchronously. 

```
-(void)payAmount:(SNCTransactionAmount *)amount withHandler:(SNCPaymentMethodHandler)handler;
```

If your bank supports Open Bank API-s, the transaction will be fully processed by the SDK. However, is your bank doesn’t support the Open Bank API-s, you should process the transaction, and pass the payment reference in the `SNCTransactionMetadata` object. 

```
@implementation SNCBankTransactionMetadata

- (NSDictionary <SNCTransactionMetadataKey, NSString *> *)serialized {
    return @{
             SNCTransactionMetadataKeyCurrency: @"CHF",
             SNCTransactionMetadataKeyAmount: [NSString stringWithFormat:@"%ld", (long)self.amount.integerValue],
             SNCTransactionMetadataKeyPaymentMethod: @"DIRECT_DEBIT",
             SNCTransactionMetadataKeyPaymentMethodId: @"hbl",
             SNCTransactionMetadataKeyType: @"atm",
             SNCTransactionMetadataKeyOpen: @"true",
             };
}

@end
```
