// Copyright 2018-2019 Yubico AB
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "YKFAccessoryConnection.h"


/*!
 @protocol YKFManagerDelegate
 
 @abstract
   Implement this protocol to get notifications when a connection to the YubiKey is established or broken.
 */
@protocol YKFManagerDelegate <NSObject>

/*!
 @method didConnectAccessory:connection
 
 @abstract
    The YubiKey SDK did connect to a Accessory Yubikey.
 
 @param connection
    The YKFAccessoryConnection to the YubiKey.
 */
- (void)didConnectAccessory:(YKFAccessoryConnection *_Nonnull)connection;

/*!
 @method didDisconnectAccessory:connection:error
 
 @abstract
    The YubiKey SDK did connect to a Accessory Yubikey.

 @param connection
    The YKFAccessoryConnection to the YubiKey that did disconnect.
 
 @method error
    If the disconnection was unexpted an NSError will be passed.
  */
- (void)didDisconnectAccessory:(YKFAccessoryConnection *_Nonnull)connection error:(NSError *_Nullable)error;

@end


/*!
 @interface YubiKitManager
 
 @abstract
    Provides the main access point interface for YubiKit.
 */
@interface YubiKitManager : NSObject

/*!
 @property delegate
 
 @abstract
    The delegate must conform to the YKFManagerDelegate protocol. Setting this delegate will allow you
    to get notifications when a connection to the YubiKey is established or broken.
 */
@property(nonatomic, weak) id<YKFManagerDelegate> _Nullable delegate;

/*!
 @method startAccessoryConnection
 
 @abstract
    Start the accessory connection.
 
 @discussion
    Do this when the application becomes active to continuosly listen for a YubiKey inserted into the Lightning Port.
 */
- (void)startAccessoryConnection;

/*!
 @method stopAccessoryConnection
 
 @abstract
    Stop the accessory connection.
 */
- (void)stopAccessoryConnection;

/*!
 @property shared
 
 @abstract
    YubiKitManager is a singleton and should be accessed only by using the shared instance provided by this property.
 */
@property (class, nonatomic, readonly, nonnull) YubiKitManager *shared;

/*
 Not available: use the shared property from YubiKitManager to retreive the shared single instance.
 */
- (nonnull instancetype)init NS_UNAVAILABLE;

@end
