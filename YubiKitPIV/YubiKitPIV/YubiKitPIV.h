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

#import "YubiKitManager.h"
#import "YubiKitLogger.h"
#import "YubiKitConfiguration.h"
#import "YubiKitExternalLocalization.h"
#import "YubiKitDeviceCapabilities.h"
#import "YKFConnectionProtocol.h"
#import "YKFAccessoryConnection.h"
#import "YKFAccessoryDescription.h"
#import "YKFSelectApplicationAPDU.h"
#import "YKFSessionError.h"
#import "YKFAPDUError.h"
#import "YKFSmartCardInterface.h"
#import "YKFFeature.h"
#import "YKFVersion.h"
#import "YKFPIVSession.h"
#import "YKFPIVSessionFeatures.h"
#import "YKFPIVManagementKeyType.h"
#import "YKFPIVManagementKeyMetadata.h"
#import "YKFPIVKeyType.h"
#import "YKFManagementSession.h"
#import "YKFSlot.h"
#import "YKFPCSC.h"
#import "YKFPCSCLayer.h"
#import "YKFNSDataAdditions.h"
