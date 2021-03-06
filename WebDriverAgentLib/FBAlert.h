/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <Foundation/Foundation.h>

@class XCUIApplication;
@class XCUIElement;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const FBAlertObstructingElementException;

/**
 Alert helper class that abstracts alert handling
 */
@interface FBAlert : NSObject

/**
 Creates alert helper for given application
 */
+ (instancetype)alertWithApplication:(XCUIApplication *)application;

/**
 Determins whether alert is present
 */
- (BOOL)isPresent;

/**
 Returns alert's title and description sparated by new lines
 */
- (nullable NSString *)text;

/**
 Accepts alert, if present

 @param error If there is an error, upon return contains an NSError object that describes the problem.
 @return YES if the operation succeeds, otherwise NO.
 */
- (BOOL)acceptWithError:(NSError **)error;

/**
 Dismisses alert, if present

 @param error If there is an error, upon return contains an NSError object that describes the problem.
 @return YES if the operation succeeds, otherwise NO.
 */
- (BOOL)dismissWithError:(NSError **)error;

/**
 Checks if given element is obstructed by alert, if so throws FBAlertObstructingElementException

 @param element checked element
 */
- (void)checkIfObstructsElement:(XCUIElement *)element;

/**
 Filters out elements obstructed by alert

 @param elements array of elements we want to filter
 @return elements not obstructed by alert
 */
- (NSArray<XCUIElement *> *)filterObstructedElements:(NSArray<XCUIElement *> *)elements;

@end

NS_ASSUME_NONNULL_END
