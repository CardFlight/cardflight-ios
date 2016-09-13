Pod::Spec.new do |s|
  s.name                  = "CardFlight"
  s.version               = "3.5"
  s.summary               = "CardFlight's iOS SDK Library"
  s.homepage              = "https://cardflight.com"
  s.author                = { "CardFlight" => "support@cardflight.com" }
  s.platform              = :ios, '8.0'
  s.source                = { :git => "https://github.com/CardFlight/cardflight-ios.git", :tag => s.version.to_s }
  s.preserve_paths        = 'libCardFlightLibrary.a'
  s.frameworks            = 'AVFoundation', 'AudioToolbox', 'MediaPlayer', 'MessageUI', 'ExternalAccessory'
  s.libraries             = 'stdc++.6.0.9'
  s.requires_arc          = true
  s.xcconfig              =  { 'LIBRARY_SEARCH_PATHS' => '"$(PODS_ROOT)/CardFlight"' }
  s.default_subspec       = 'AudioJack'

  s.license = {
    :type => 'commercial',
    :text => 'Copyright 2016 Cardflight, Inc. All rights reserved.'
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
    attache.requires_arc            = true
    attache.deprecated              = true
  end

end
