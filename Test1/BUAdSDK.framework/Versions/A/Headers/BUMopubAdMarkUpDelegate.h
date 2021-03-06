//
//  BUMopubAdMarkUpDelegate.h
//  BUAdSDK
//
//  Created by Siwant on 2020/4/24.
//  Copyright © 2020 bytedance. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class BUAdSlot;

@protocol BUMopubAdMarkUpDelegate <NSObject>
@optional

/** Mopub AdMarkUp
  */
- (void)setAdMarkup:(NSString *)adm;
- (void)setMopubAdMarkUp:(NSString *)adm DEPRECATED_MSG_ATTRIBUTE("please use -setAdMarkup: instead");

/// Bidding Token. Now for MSDK in domestic, used for every ad type.
- (NSString *)biddingToken;

/** Mopub Adaptor get AD type from rit
  *   @return  @{@"adSlotType": @(1), @"renderType": @(1)}
  *   adSlotType refer from BUAdSlotAdType in "BUAdSlot.h"
  *   showType: @"1" express AD   @"2" native AD
  */
+ (nullable NSDictionary *)AdTypeWithRit:(NSString *)rit error:(NSError **)error;

/** Mopub bidding Adaptor get AD type from adm
  *  @return  @{@"adSlotType": @(1), @"renderType": @(1)}
  *  adSlotType refer from BUAdSlotAdType in "BUAdSlot.h"
  *  showType: @"1" express AD   @"2" native AD
  */
+ (NSDictionary *)AdTypeWithAdMarkUp:(NSString *)adm;


/// Mopub Bidding Token
+ (NSString *)mopubBiddingToken DEPRECATED_MSG_ATTRIBUTE("please use +getBiddingToken: instead");

/// overseas bidding token
/// @param slotID  the unique identifier of  ad.
+ (NSString *)getBiddingToken:(nullable NSString *)slotID;

@end

NS_ASSUME_NONNULL_END
