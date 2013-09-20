CardFlight's iOS SDK Library
=================

*CardFlight is currently in private beta. If you would like to get ahold of our private beta, Request Access at [https://getcardflight.com](https://getcardflight.com/) or email [devs@getcardflight.com](mailto: devs@getcardflight.com).*

Introduction
------------

The CardFlight's iOS SDK is used to process card present and card not-present transactions in your iOS application.

CardFlight's SDK's is based around keeping it as simple as possible, however keeping the highest level of [security](https://developers.getcardflight.com/help/security) at the forefront of all that we do. Taking out the pain of PCI-compliance when building your app.

Authenticationis done thorugh your API Keys and processing is done through the Account Tokens. All connections to CardFlight's API id done thorugh HTTPS over HSTS.

[JSON](http://www.json.org) is used where possible upon returning responses from the API, including errors.


*CardFlight is currently in private beta. If you would like to get a hold of our private beta, register here at [https://getcardflight.com](https://getcardflight.com/request_access) or email at [devs@getcardflight.com](mailto: devs@getcardflight.com). In the meantime, please watch this repo as well will be pushing our first version very soon.*

Setup
----------

Add the files **CardFlight-iOS.a** and **CardFlight.h** files into your project. Add the following frameworks to you project:

- AVFoundation.framework 
- AudioToolbox.framework 
- MediaPlayer.framework 
- MessageUI.framework 
- UIKit.framework 
- Foundation.framework
- CoreGraphics.framework

Import the **CardFlight.h** file in any UIViewController or UIViewController subclass header file where you want to access the CardFlight user interface.

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

- [Errors](https://developers.getcardflight.com/docs/api#errors)
- [Initialization](https://developers.getcardflight.com/docs/api#initialization)
- [Swipe Card](https://developers.getcardflight.com/docs/api#swipe_card)
- [Swipe Response](https://developers.getcardflight.com/docs/api#swipe_card_response)
- [Keyed Entry](https://developers.getcardflight.com/docs/api#keyed_entry)
- [Keyed Response](https://developers.getcardflight.com/docs/api#keyed_response)
- [Process Payment](https://developers.getcardflight.com/docs/api#process_payment)


Supported Platforms
-----------------------

All CardFlight readers work on **iOS version 3.1.3 or above**. Our SDK supports a wide array of iOS platforms. [Click here](https://developers.getcardflight.com/docs/ios) to view an updated list.


Looking for Android?
-----------------

We've got you covered. [Click here](https://github.com/CardFlight/cardflight-android) to learn more about our CardFlight Android SDK. 


