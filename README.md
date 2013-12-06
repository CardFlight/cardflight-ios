CardFlight iOS SDK Library
=================

Introduction
------------

The CardFlight iOS SDK is used to process card present and card not-present transactions in your iOS application.

CardFlight's SDK is based around keeping it as simple as possible while keeping the highest level of [security](https://developers.getcardflight.com/help/security) at the forefront of all that we do. Take out the pain of PCI-compliance when building your app.

Authentication is done through your API Keys and processing is done through the Account Tokens. All connections to CardFlight's API are done through HTTPS over HSTS.

Setup
----------

### CocoaPods Installation

[CocoaPods](http://www.cocoapods.org/) is the recommended method of installing CardFlight.

##### Podfile

```ruby
platform :ios, '7.0'
pod "CardFlight"
```

### Manual Installation

Add the **CardFlight-iOS.a** and all header files into your project. Add the following frameworks to you project:

- AVFoundation.framework 
- AudioToolbox.framework 
- MediaPlayer.framework 
- MessageUI.framework 
- CoreGraphics.framework

Add **CardFlight.h** to your AppDelegate and set the API Key and Account Token.

##### Example

```
#import "CardFlight.h"
[[CardFlight sharedInstance] setAPIToken:@"e9cb15260f08e438b782952895d4ba4d"
                            AccountToken:@"acc_04ff8bf654afb265"];
```

The CardFlight SDK is broken into easy-to-manage components. You just include the ones that you want to use in the header files of the classes that need to access those components.

SDK Documentation
--------------

- [Errors](https://developers.getcardflight.com/docs/api#errors)
- [Reader Initialization](https://developers.getcardflight.com/docs/api#reader_initialization)
- [Swipe Card](https://developers.getcardflight.com/docs/api#swipe_card)
- [Swipe Response](https://developers.getcardflight.com/docs/api#swipe_card_response)
- [Keyed Entry](https://developers.getcardflight.com/docs/api#keyed_entry)
- [Keyed Response](https://developers.getcardflight.com/docs/api#keyed_response)
- [Charge Card](https://developers.getcardflight.com/docs/api#process_payment)
- [Refund Charge](https://developers.getcardflight.com/docs/api#refund_charge)


Supported Platforms
-----------------------

All CardFlight readers work on **iOS version 5.0 or above**. Our SDK supports a wide array of iOS platforms. [Click here](https://developers.getcardflight.com/docs/ios) to view an updated list.


Looking for Android?
-----------------

We've got you covered. [Click here](https://github.com/CardFlight/cardflight-android) to learn more about our CardFlight Android SDK. 


