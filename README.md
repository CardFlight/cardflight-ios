CardFlight's iOS SDK Library
=================


Introduction
------------

CardFlight's API is based around keeping it as simple as possible, however keeping the highest level of [security](http://#) at the forefront of all that we do. Taking out the pain of PCI-compliance when building your app.

Authenticationis done thorugh your API Keys and processing is done through the Account Tokens. All connections to CardFlight's API id done thorugh HTTPS over HSTS.

[JSON](http://www.json.org) is used where possible upon returning responses from the API, including errors.


Setup
----------

Import the 'CardFlight.h' file in any UIViewController or UIViewController subclass header file where you want to access the CardFlight user interface.

##### Example

```
#import "CardFlight.h"
```

You will also need to set the CardFlight delegate within the Controller.

```
@interface ViewController : UIViewController  {}
```

SDK Documentation
--------------

Click on the topics below to learn more about our SDK.

| Topics | 
| ------------ | 
| [Errors](https://developers.getcardflight.com/docs/api#errors) |
| [Initialization](https://developers.getcardflight.com/docs/api#initialization)|
| [Swipe Card](https://developers.getcardflight.com/docs/api#swipe_card)| 
| [Swipe Response](https://developers.getcardflight.com/docs/api#swipe_card_response)|
| [Keyed Entry](https://developers.getcardflight.com/docs/api#keyed_entry)|
| [Keyed Response](https://developers.getcardflight.com/docs/api#keyed_response)|
| [Process Payment](https://developers.getcardflight.com/docs/api#process_payment)|


Supported Platforms
-----------------------

Our SDK supports a wide array of iOS platforms. [Click here](https://developers.getcardflight.com/docs/ios) to view an updated list.


Looking for Android?
-----------------

We've got you covered. [Click here](https://github.com/CardFlight/cardflight-android) to learn more about our Android SDK. 


Questions?
--------

CardFlight is currently in private beta. If you would like to get a hold of our private beta, register here at https://getcardflight.com or email at devs@getcardflight.com. In the meantime, please watch this repo as well will be pushing our first version very soon.
