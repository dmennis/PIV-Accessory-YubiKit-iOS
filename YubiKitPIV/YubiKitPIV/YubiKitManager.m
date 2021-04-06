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

#import <ExternalAccessory/ExternalAccessory.h>

#import "YubiKitManager.h"
#import "YKFAccessoryConnectionConfiguration.h"
#import "YKFAccessoryConnection+Private.h"

@interface YubiKitManager()<YKFAccessoryConnectionDelegate>

@property (nonatomic, readwrite) YKFAccessoryConnection *accessorySession;

@end

@implementation YubiKitManager

@synthesize delegate;

static YubiKitManager *sharedInstance;

+ (YubiKitManager *)shared {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[YubiKitManager alloc] initOnce];
    });
    return sharedInstance;
}

- (instancetype)initOnce {
    self = [super init];
    if (self) {
        
        YKFAccessoryConnectionConfiguration *configuration = [[YKFAccessoryConnectionConfiguration alloc] init];
        EAAccessoryManager *accessoryManager = [EAAccessoryManager sharedAccessoryManager];
        YKFAccessoryConnection *accessoryConnection = [[YKFAccessoryConnection alloc] initWithAccessoryManager:accessoryManager configuration:configuration];
        accessoryConnection.delegate = self;
        self.accessorySession = accessoryConnection;
    }
    return self;
}

//- (void)setDelegate:(id<YKFManagerDelegate>)delegate {
//    self.delegate = delegate;
//}

- (void)startAccessoryConnection {
    [self.accessorySession start];
}

- (void)stopAccessoryConnection {
    [self.accessorySession stop];
}

- (void)didConnectAccessory:(YKFAccessoryConnection *_Nonnull)connection {
    [self.delegate didConnectAccessory:connection];
}

- (void)didDisconnectAccessory:(YKFAccessoryConnection *_Nonnull)connection error:(NSError * _Nullable)error {
    [self.delegate didDisconnectAccessory:connection error:error];
}

@end
