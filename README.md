# Deprecated Repo

This repo has been deprecated and is no longer being maintained or updated.

CardFlight v3 can now be found [here](https://github.com/CardFlight/cardflight-v3-ios)


CardFlight iOS SDK Library
=================

Introduction
------------

The CardFlight iOS SDK is used to process card present and card not-present transactions in your iOS application.

CardFlight's SDK is based around keeping it as simple as possible while keeping the highest level of [security](https://developers.cardflight.com/help/security) at the forefront of all that we do. Take out the pain of PCI-compliance when building your app.

Authentication is done through your API Keys and processing is done through the Account Tokens. All connections to CardFlight's API are done through HTTPS over HSTS.

Setup
----------

### CocoaPods Installation

[CocoaPods](http://www.cocoapods.org/) is the recommended method of installing CardFlight.

##### Podfile

```ruby
platform :ios, '8.0'
pod "CardFlight"
```

### Manual Installation

Add the **libCardFlightLibrary.a** and all header files into your project. Add the following frameworks to you project:

- AVFoundation.framework
- AudioToolbox.framework
- MediaPlayer.framework
- MessageUI.framework
- CoreGraphics.framework
- ExternalAccessory.framework
- libstdc++.6.0.9.dylib

### Logging

The SDK includes a logging mode to assist with debugging that will print out statements in the console. Be sure to disable it in the production code.

```
- (void)setLogging:(BOOL)logging;
```

### Initialize

Add **CardFlight.h** to your AppDelegate and set the API Key and Account Token.

##### Example

```
[[CFTSessionManager sharedInstance] setApiToken:@"e9cb15260f08e438b782952895d4ba4d"
accountToken:@"acc_04ff8bf654afb265"];
```

The CardFlight SDK is broken into easy-to-manage components. You just include the ones that you want to use in the header files of the classes that need to access those components.

SDK Documentation
--------------

- [Errors](https://developers.cardflight.com/docs/api#errors)
- [Reader Initialization](https://developers.cardflight.com/docs/api#reader_initialization)
- [Swipe Card](https://developers.cardflight.com/docs/api#swipe_card)
- [Swipe Response](https://developers.cardflight.com/docs/api#swipe_card_response)
- [Keyed Entry](https://developers.cardflight.com/docs/api#keyed_entry)
- [Keyed Response](https://developers.cardflight.com/docs/api#keyed_response)
- [Charge Card](https://developers.cardflight.com/docs/api#process_payment)
- [Refund Charge](https://developers.cardflight.com/docs/api#refund_charge)


Supported Platforms
-----------------------

All CardFlight readers work on **iOS version 8.0 or above**. Our SDK supports a wide array of iOS platforms. [Click here](https://developers.cardflight.com/docs/ios) to view an updated list.


Looking for Android?
-----------------

We've got you covered. [Click here](https://github.com/CardFlight/cardflight-android) to learn more about our CardFlight Android SDK.
