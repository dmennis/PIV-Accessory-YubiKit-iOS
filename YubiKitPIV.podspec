Pod::Spec.new do |s|
  s.name     = 'YubiKitPIV'
  s.version  = '4.0.0'
  s.license  = 'Apache 2.0'
  s.summary  = 'PIVYubiKit is a SLIM PIV iOS library provided by Yubico to interact with PIV module on a YubiKey'
  s.homepage = 'https://github.com/YubicoLabs/slim-PIV-yubikit-ios'
  s.author   = 'YubicoDev'
  s.source   = { :git => 'https://github.com/YubicoLabs/slim-PIV-yubikit-ios.git', :tag => s.version }
  s.requires_arc = true

  s.source_files = 'YubiKitPIV/YubiKitPIV/**/*.{h,m}'

  s.ios.deployment_target = '13.0'
end
