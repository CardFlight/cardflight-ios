### iOS API Reference

#### Introduction

CardFlight's API is based around keeping it as simple as possible, however keeping the highest level of [security](http://#) at the forefront of all that we do. Taking out the pain of PCI-compliance when building your app.

Authenticationis done thorugh your API Keys and processing is done through the Account Tokens. All connections to CardFlight's API id done thorugh HTTPS over HSTS.

[JSON](http://www.json.org) is used where possible upon returning responses from the API, including errors.

---

#### Errors

CardFlight errors are passed back whenever an issue occurs within our server API. We recommend trying to gracefully handle all errors that happen to ensure a smoother user interfase for your app. 

All errors return a human-readable message giving more details about the error. Depending on the error, some may be able to be shown directly to the user of the app. 

For card errors, a short string code is pased back which is lised to below describing the error that has occurred.

##### Types

**api_error**

API errors cover any type of problem related to the API. For example an invalid Merchant Account Token, an issue processing with your merchant account, or even problem's with CardFlight's servers.


**card_error**

Card errors occur whenever there is an issue with processing the card details, whether it be encryption issues or invalid card details. Developers should expect to handle these types of errors in their app.

##### Codes

**invalid_decryption**

There was an issue with the decryption of the mag stripe data.

**invalid_test_card**

The card you are using for testing is invalid. ie. The card number ends in an odd number.

___

#### Setup

Import the 'CardFlight.h' file in any UIViewController or UIViewController subclass header file where you want to access the CardFlight user interface.

##### Example

```
#import "CardFlight.h"
```

You will also need to set the CardFlight delegate within the Controller.

```
@interface ViewController : UIViewController  {}
```
___

#### Initialization

To access your CardFlight account you will need to set your Developer API key and the associated Merchant Account Token that you wish to connect to when making payments.

##### Example

```
[[CardFlight sharedInstance] setAPIToken:@"e9cb15260f08e738b782952895d4ba4f" AccountToken:@"acc_04ff8bf650afb268" andDelegate:self];
```


###### Arguments

**API Token:**

The API token for your CardFlight account that you received upon registration. This can be either a Production or Test API Key.

**Account Token:**

The Merchant Account Token you wish to process payments with.

---

#### Swipe Card Response

This method will process the swiping action and return the first name, last name, and last 4 digits as (if the swipe was a success), or an error message if not successful(timeout, incorrect swipe, hardware error etc.)

##### Method

-(void)swipeResponse:(NSData \*)data andError:(NSError *)error;


##### Example

```
-(void)swipeResponse:(NSData *)data andError:(NSError *)error
{
    if (!error)
    {
        NSDictionary *myDict =[NSJSONSerialization JSONObjectWithData:data options:NSJSONReadingMutableContainers error:nil];

        nameTextField.text = [myDict objectForKey:@"name"];
        numberTextField.text = [myDict objectForKey:@"card number"];
        expDateTextField.text = [NSString stringWithFormat:@"%@/%@", [myDict objectForKey:@"exp month"], [myDict objectForKey:@"exp year"]];
    }
    else
    {
        //Error management goes here
    }
}
```

###### Attributes

**data:**

This is a boolean value which determines if you want to use the default dialog built within CardFlight. Set this to false and create your own custom dialog message for notifying the user that they can now swipe the card.

**error:**

This is a boolean value which determines if you want to use the default dialog built within CardFlight. Set this to false and create your own custom dialog message for notifying the user that they can now swipe the card.

___

#### Keyed Entry

To use the CardFlight keyed entry facility, rather than the swiping of a card, this method will initiate the keyed entry screen for entering the relevant card data.

##### Method


-(void)startKeyedEntry;

##### Example

```
[[CardFlight sharedInstance] startKeyedEntry];
```
___

#### Keyed Entry Response

This will return the keyed entry card details through a dictionary object. This will allow you to display the card details as you please in your app. Note that full card numbers will be displayed with masked (ie. xxxx xxxx xxxx 1234)

##### Method

-(void)manualEntryDictionary:(NSDictionary *)dictionary;

##### Example

```
-(void)manualEntryDictionary:(NSDictionary *)dictionary
{
    nameTextField.text = [dictionary objectForKey:@"name"];
    numberTextField.text = [dictionary objectForKey:@"number"];
    expDateTextField.text = [NSString stringWithFormat:@"%@/%@", [dictionary objectForKey:@"expiration month"], [dictionary objectForKey:@"expiration year"]];
}

```

###### Attributes

**dictionary:**

This is the dictionary object that is used to pass back the card data which is used for display purposes within your app. It contains 4 keys, that being @"name", @"number", @"expiration month", and @"expiration year"

___

#### Process Payment

Use this method to process a payment to your merchant account. If in test mode, this method will simple return a success object and create a transaction for the relevant merchant account. Otherwise within production mode, this will actually charge the consumers card with the desired amount.

##### Method

-(void)processPaymentWithTransaction:(NSDictionary *)transaction;

##### Example

```
NSMutableDictionary *transaction = [NSMutableDictionary dictionary];

[transaction setObject:descriptionTextField.text forKey:@"description"];
[transaction setObject:[NSNumber numberWithFloat:priceTextField.text.floatValue] forKey:@"amount"];
[transaction setObject:currencyTextField.text forKey:@"currency"];

[[CardFlight sharedInstance] processPaymentWithTransaction:transaction];

```

###### Attributes

**transaction:**

This is NSDictionary that contains a float amount (required) and 2 strings description (optional) and currency (optional).

