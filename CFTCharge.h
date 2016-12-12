/*
 *****************************************************************
 * CFTCharge.h
 *
 * Is returned after a successful charge is made.
 * Contains all the information about a charge and has the ability
 * to refund it, either partially or in full
 *
 * Copyright (c) 2015 CardFlight Inc. All rights reserved.
 *****************************************************************
 */

#import <Foundation/Foundation.h>
#import "CFTSessionManager.h"
#import "CFTAPIResource.h"

@interface CFTCharge : CFTAPIResource

@property (nonatomic) NSDecimalNumber *amount;
@property (nonatomic, copy) NSString *token;
@property (nonatomic, copy) NSString *referenceID;
@property (nonatomic) BOOL isRefunded;
@property (nonatomic) BOOL isVoided;
@property (nonatomic) NSDecimalNumber *amountRefunded;
@property (nonatomic) NSDate *created;
@property (nonatomic, copy) NSDictionary *metadata;

/*!
 * @brief Create a cash charge
 * @param chargeDictionary NSDictionary containing charge details
 * @param success Block containing CFTCharge, executed on success
 * @param failure Block containing NSError, executed on failure
 * @discussion Method to create a cash charge with the details in the chargeDictionary.
 * chargeDictionary parameters:
 *      amount - NSDecimalNumber containing amount to charge
 *      callback_url - Optional - NSURL of callback URL to trigger
 *      description - Optional - NSString of charge description
 *      customer_id - Optional - NSString of customer ID being charged
 *      currency - Optional - NSString of currency code, defaults to USD
 *      merchant_id - Optional - NSString of Braintree submerchant ID
 *      service_fee - Optional - NSDecimalNumber containing the fee to charge
 * Added in 3.0
 */
+ (void)cashChargeWithParameters:(NSDictionary *)chargeDictionary
                         success:(void(^)(CFTCharge *charge))success
                         failure:(void(^)(NSError *error))failure;

/*!
 * @brief Refund a charge
 * @param token Charge token to be refunded
 * @param amount NSDecimalNumber of amount to be refunded
 * @param callbackURL NSURL of callback URL to trigger
 * @param success Block containing CFTCharge, executed on success
 * @param failure Block containing NSError, executed on failure
 * @discussion Refund a charge by passing in the charge token
 * and amount to refund in dollars and cents.
 * Updated in 4.0
 * @warning Amount cannot exceed original charge amount
 */
+ (void)refundChargeWithToken:(NSString *)token
                    andAmount:(NSDecimalNumber *)amount
                  callbackURL:(NSURL *)callbackURL
                      success:(void(^)(CFTCharge *charge))success
                      failure:(void(^)(NSError *error))failure;

/*!
 * @brief Capture a previously authorized charge
 * @param token Charge token of previously authorized charge
 * @param amount NSDecimalAmount to capture, nil for original amount
 * @param success Block containing CFTCharge, executed on success
 * @param failure Block containing NSError, executed on failure
 * @discussion Capture a previously authorized charge by passing the charge token and the amount
 * to capture. If the amount is nil then amount of the original authorization will be captured.
 * Only swiped or manually entered transactions can be captured.
 * Added in 1.9
 * @warning EMV transactions are not eligible for auth and capture.
 */
+ (void)captureChargeWithToken:(NSString *)token
                     andAmount:(NSDecimalNumber *)amount
                       success:(void(^)(CFTCharge *charge))success
                       failure:(void(^)(NSError *error))failure;

/*!
 * @brief Void a charge
 * @param token Charge token to be voided
 * @param callbackURL NSURL of callback URL to trigger
 * @param success Block executed on success, isVoided is set to YES
 * @param failure Block containing NSError, executed on failure
 * @discussion Void a charge that has not batched yet.
 * Updated in 4.0
 */
+ (void)voidChargeWithToken:(NSString *)token
                callbackURL:(NSURL *)callbackURL
                    success:(void(^)(void))success
                    failure:(void(^)(NSError *error))failure;

/*!
 * @brief Upload a signature
 * @param token Charge token of previously approved charge
 * @param signatureData NSData representation of a signature image
 * @param success Block executed on successful upload
 * @param failure Block containing NSError, executed on failure
 * @discussion Attach a signature to a previously approved charge. The signatureData
 * must be an NSData representation of an image. Only for swiped or manually entered
 * charges.
 * Added in 3.0
 */
+ (void)attachSignatureWithToken:(NSString *)token
                   signatureData:(NSData *)signatureData
                         success:(void(^)(void))success
                         failure:(void(^)(NSError *error))failure;

/*!
 * @brief Retrieve receipt data
 * @param token Charge token of previously approved charge
 * @param success Block containing dictionary of receipt data
 * @param failure Block containing NSError, executed on failure
 * @discussion Retrieve the data necessary to build a receipt for previously
 * approved charge.
 * Added in 3.5.1
 */
+ (void)receiptDataWithToken:(NSString *)token
                     success:(void(^)(NSDictionary *receiptData))success
                     failure:(void(^)(NSError *error))failure;

// ******************** DEPRECATED ********************

/*!
 * @brief Refund a charge
 * @param token Charge token to be refunded
 * @param amount NSDecimalNumber of amount to be refunded
 * @param success Block containing CFTCharge, executed on success
 * @param failure Block containing NSError, executed on failure
 * @discussion Refund a charge by passing in the charge token
 * and amount to refund in dollars and cents.
 * Deprecated in 3.5.1
 * @warning Amount cannot exceed original charge amount
 *
 * THIS WILL BE REMOVED IN A LATER RELEASE
 */
+ (void)refundChargeWithToken:(NSString *)token
                    andAmount:(NSDecimalNumber *)amount
                      success:(void(^)(CFTCharge *charge))success
                      failure:(void(^)(NSError *error))failure __deprecated;

/*!
 * @brief Void a charge
 * @param success Block executed on success, isVoided is set to YES
 * @param failure Block containing NSError, executed on failure
 * @discussion Void a charge that has not batched yet.
 * Deprecated in 3.5.1
 *
 * THIS WILL BE REMOVED IN A LATER RELEASE
 */
+ (void)voidChargeWithWithToken:(NSString *)token
                        success:(void(^)(void))success
                        failure:(void(^)(NSError *error))failure __deprecated;

@end
