// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "YubiKitPIV",
    platforms: [
        .iOS(.v13)
    ],
    products: [
        .library(
            name: "YubiKitPIV",
            targets: ["YubiKitPIV"]),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "YubiKitPIV",
            path: "YubiKitPIV/YubiKitPIV",
            publicHeadersPath: "SPMHeaderLinks")
    ]
)
