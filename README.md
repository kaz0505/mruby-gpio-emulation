mrbgem-gpio-emulation
=====================

mrbgem for GPIO, console emulation

# Installation

- Download mruby

        git clone http://github.com/mruby/mruby

- Configure "build_config.rb" 

Insert the following one line after "conf.gembox 'default'" in "build_config.rb".

        conf.gem :github => 'kaz0505/mruby-gpio-emulation'

- Build mruby

        make



----

# Example

        Gpio.pinMode 1, Gpio::OUTPUT
        Gpio.pinMode 2, Gpio::INPUT
        
        Gpio.digitalWrite 1, Gpio::HIGH
        Gpio.digitalWrite 2, Gpio::LOW

The gpio emulation result is printed to console.

----

# Class Reference


