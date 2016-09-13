/*
 *****************************************************************
 * CFTEnum.h
 *
 * Copyright (c) 2015 CardFlight Inc. All rights reserved.
 *****************************************************************
 */

typedef NS_ENUM(NSUInteger, CFTEMVMessage) {
    EMVMessage_UNKNOWN = 0,
    EMVMessage_AMOUNT_OK = 1,
    EMVMessage_APPLICATION_BLOCKED = 2,
    EMVMessage_APPROVED = 3,
    EMVMessage_CALL_BANK = 4,
    EMVMessage_CAPK_FAIL = 5,
    EMVMessage_CARD_BLOCKED = 6,
    EMVMessage_CARD_ERROR = 7,
    EMVMessage_CARD_NOT_SUPPORTED = 8,
    EMVMessage_CLEAR_DISPLAY = 9,
    EMVMEssage_CONDITIONS_NOT_SATISFIED = 10,
    EMVMessage_DECLINED = 11,
    EMVMessage_DEVICE_ERROR = 12,
    EMVMessage_DIP_OR_SWIPE = 13,
    EMVMessage_ENTER_AMOUNT = 14,
    EMVMessage_ENTER_PIN = 15,
    EMVMessage_ICC_CARD_REMOVED = 16,
    EMVMessage_INCORRECT_PIN = 17,
    EMVMessage_INSERT_CARD = 18,
    EMVMessage_INVALID_ICC_DATA = 19,
    EMVMessage_MISSING_DATA = 20,
    EMVMessage_NO_EMV_APP = 21,
    EMVMessage_NOT_ACCEPTED = 22,
    EMVMessage_NOT_ICC = 23,
    EMVMessage_ONLINE_REQUIRED = 24,
    EMVMessage_PIN_OK = 25,
    EMVMessage_PLEASE_WAIT = 26,
    EMVMessage_PRESENT_ONLY_ONE_CARD = 27,
    EMVMessage_PROCESSING = 28,
    EMVMessage_PROCESSING_ERROR = 29,
    EMVMessage_REMOVE_CARD = 30,
    EMVMessage_FALLBACK = 31,
    EMVMessage_SET_AMOUNT_CANCEL_OR_TIMEOUT = 32,
    EMVMessage_TERMINATED = 33,
    EMVMessage_TRANSACTION_CANCELLED = 34,
    EMVMessage_TRY_AGAIN = 35,
    EMVMessage_TRY_TAP_AGAIN = 36,
    EMVMessage_TRY_DIP_AGAIN = 37,
    EMVMessage_TRY_SWIPE_AGAIN = 38,
    EMVMessage_TAP_DIP_OR_SWIPE = 39,
    EMVMessage_USE_CHIP_READER = 40,
    EMVMessage_USE_MAG_READER = 41,
    EMVMessage_WELCOME = 42,
    EMVMessage_NO_MESSAGE = 43,
    EMVMessage_NO_PERMISSION = 44
};

typedef NS_ENUM(NSUInteger, CFTEMVCardState) {
    CFTEMVCardState_UNKNOWN = 0,
    CFTEMVCardState_INSERTED = 1,
    CFTEMVCardState_WAITING_FOR_REMOVAL = 2,
    CFTEMVCardState_REMOVED = 3,
    CFTEMVCardState_TAPPED = 4
};

typedef NS_ENUM (NSUInteger, CFTCardType) {
    CFTCardTypeVisa = 0,
    CFTCardTypeMasterCard = 1,
    CFTCardTypeAmex = 2,
    CFTCardTypeDiscover = 3,
    CFTCardTypeJCB = 4,
    CFTCardTypeDinersClub = 5,
    CFTCardTypeUnknown = 6
};

typedef NS_ENUM (NSUInteger, CFTReaderState) {
    ReaderState_UNKNOWN = 0,
    ReaderState_WAITING_FOR_CONNECT = 1,
    ReaderState_ATTACHED = 2,
    ReaderState_CONNECTED = 3,
    ReaderState_WAITING_FOR_TAP = 4,
    ReaderState_WAITING_FOR_DIP = 5,
    ReaderState_WAITING_FOR_SWIPE = 6,
    ReaderState_SWIPE_DETECTED = 7,
    ReaderState_CARD_INSERTED = 8,
    ReaderState_REMOVE_CARD = 9,
    ReaderState_DISCONNECTED = 10,
    ReaderState_NOT_FOUND = 11,
    ReaderState_NO_PERMISSION = 12
};

typedef NS_ENUM(NSUInteger, CFTReaderType) {
    CFTReaderType_UNKNOWN = 0,
    CFTReaderType_SHUTTLE = 1,
    CFTReaderType_BTMAG = 2,
    CFTReaderType_A100 = 3,
    CFTReaderType_A200 = 4,
    CFTReaderType_B550 = 5,
    CFTReaderType_B500 = 6,
    CFTReaderType_A250 = 7,
    CFTReaderType_B200 = 8,
    CFTReaderType_B250 = 9
};
