mrbgem-gpio-emulation
=====================

mrbgem for pc emulation

# 使用方法

0. mruby をダウンロードする

    git clone http://github.com/mruby/mruby

0. build_config.rb の設定をする

「conf.gembox 'default'」の前あたりに以下の１行をを追加する。

    conf.gem :github => 'kaz0505/mruby-gpio-emulation'

0. make

----

例えば以下のサンプルを動かせます。


    Gpio.pinmode 1, Gpio::OUTPUT
    Gpio.pinmode 2, Gpio::INPUT
    
    Gpio.digitalWrite 1, Gpio::HIGH
    Gpio.digitalWrite 2, Gpio::LOW


----


