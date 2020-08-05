Pod::Spec.new do |spec|

  spec.name         = "sonect-core-ios"
  spec.version      = "1.0.4"
  spec.summary      = "Sonect Core SDK"
  spec.description  = <<-DESC
  This is the Sonect Core SDK public podspec. 
                   DESC

  spec.homepage     = "https://github.com/sonect/sonect-core-ios"
  spec.license      = { :type => "Sonect Closed Source", :text => <<-LICENSE
                    Copyright (C) Sonect AG - All Rights Reserved
                    Unauthorized copying of this file, and the Sonect SDK via any medium is strictly prohibited
                    Proprietary and confidential
                    Sonect, January 2020. 
                    LICENSE
               }
  spec.author             = { "sonect" => "marko.hlebar@sonect.ch" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :http => "https://github.com/sonect/sonect-core-ios/releases/download/#{spec.version}/SonectCoreSDK_Cocoapods.framework.zip" }
  spec.ios.vendored_frameworks = 'SonectCore.framework'

end
