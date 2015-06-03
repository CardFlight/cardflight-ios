Pod::Spec.new do |s|
  s.name                  = "CardFlight"
  s.version               = "2.0.6"
  s.summary               = "CardFlight's iOS SDK Library"
  s.homepage              = "https://getcardflight.com"
  s.author                = { "CardFlight" => "support@getcardflight.com" }
  s.platform              = :ios, '6.1'
  s.source                = { :git => "https://github.com/CardFlight/cardflight-ios.git", :tag => s.version.to_s }
  s.preserve_paths        = 'libCardFlightLibrary.a'
  s.frameworks            = 'AVFoundation', 'AudioToolbox', 'MediaPlayer', 'MessageUI'
  s.libraries             = 'stdc++.6.0.9'
  s.requires_arc          = true
  s.xcconfig              =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/CardFlight"' }
  s.default_subspec       = 'AudioJack'

  s.license = {
    :type => 'commercial',
    :text => 'Copyright 2015 Cardflight, Inc. All rights reserved.'
  }

  s.subspec 'AudioJack' do |audiojack|
    audiojack.source_files          = '*.{h,m}'
    audiojack.vendored_library      = 'libCardFlightLibrary.a'
    audiojack.exclude_files         = 'CFTAttacheReader.h', 'libCardFlightAttacheLibrary.a'
    audiojack.requires_arc          = true
  end

  s.subspec 'Attache' do |attache|
    attache.source_files            = '*.{h,m}'
    attache.vendored_library        = 'libCardFlightAttacheLibrary.a'
    attache.exclude_files           = 'CFTReader.h', 'libCardFlightLibrary.a'
    attache.framework               = 'ExternalAccessory'
    attache.requires_arc            = true
  end

end
