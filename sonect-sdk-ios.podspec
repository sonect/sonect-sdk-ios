Pod::Spec.new do |spec|

  spec.name         = "sonect-sdk-ios"
  spec.version      = "4.9.0"
  spec.summary      = "Sonect SDK"
  spec.description  = <<-DESC
  This is the Sonect SDK public podspec. 
                   DESC

  spec.homepage     = "https://github.com/sonect/sonect-sdk-ios"
  spec.license      = { :type => "Sonect Closed Source", :text => <<-LICENSE
                    Copyright (C) Sonect AG - All Rights Reserved
                    Unauthorized copying of this file, and the Sonect SDK via any medium is strictly prohibited
                    Proprietary and confidential
                    Sonect, July 2019. 
                    LICENSE
               }
  spec.author             = { "sonect" => "marko.hlebar@sonect.ch" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :http => "https://github.com/sonect/sonect-sdk-ios/releases/download/#{spec.version}/SonectSDK_Cocoapods.framework.zip" }
  spec.ios.vendored_frameworks = 'Sonect.xcframework'
  spec.dependency 'sonect-core-ios', '~> 1.4.5'

end
