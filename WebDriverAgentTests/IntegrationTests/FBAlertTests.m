/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <XCTest/XCTest.h>

#import <WebDriverAgentLib/FBAlert.h>

@interface FBAlertTests : XCTestCase

@end

@implementation FBAlertTests

- (void)setUp
{
  [super setUp];
  [[XCUIApplication new] launch];
}

- (void)testAcceptingAlert
{
  XCUIApplication *app = [XCUIApplication new];
  [app.buttons[@"Show alert"] tap];
  [[FBAlert alertWithApplication:app] acceptWithError:nil];
  sleep(1);
  XCTAssertTrue(app.alerts.count == 0, @"Alert should be dismissed");
}

@end
