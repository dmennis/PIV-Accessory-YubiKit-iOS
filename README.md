# PIV-Accessory-YubiKit-iOS
A slim version of the YubiKit iOS SDK v4 supporting only the PIV module and accessory connection.

## Integrate the library
YubiKitPIV SDK is available as a PIV YubiKit library and can be added to any new or existing iOS Xcode project through SPM only. This library supports the PIV module over the Accessory connection only.

### [Swift Package Manager Setup]

The YubiKit SDK for iOS is available Swift Package Manger (SPM). SPM is a dependency manager built into recent versions of Xcode. Go here to learn more.

Open Xcode and click "File" -> "Swift Packages" -> "Add Package Dependency..."

Paste the following URL: https://github.com/dmennis/PIV-Accessory-YubiKit-iOS

Click "Next" -> "Next" -> "Finish"

If your target project is written in Swift, you need to provide a bridge to the YubiKit library by adding #import <YubiKitPIV.h> to your bridging header. If a bridging header does not exist within your project, you can add one by following this documentation.

