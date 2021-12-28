// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SonectSDK",
    products: [
        // Products define the executables and libraries a package produces, and make them visible to other packages.
        .library(
            name: "SonectSDK",
            targets: ["Sonect"]),
    ],
    dependencies: [
        // Dependencies declare other packages that this package depends on.
        // .package(url: /* package url */, from: "1.0.0"),
    ],
    targets: [
        // Targets are the basic building blocks of a package. A target can define a module or a test suite.
        // Targets can depend on other targets in this package, and on products in packages this package depends on.
        .binaryTarget(
            name: "Sonect",
            url: "https://github.com/sonect/sonect-sdk-ios/releases/download/4.8.3/SonectSDK_Cocoapods.framework.zip",
            checksum: "da8e0149fb2c556a83c0feca77e48c1ee1eb0a44b31928c0fe5d6869f2f56d8a"
        )
    ]
)
