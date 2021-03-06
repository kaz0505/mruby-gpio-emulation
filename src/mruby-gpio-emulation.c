#include <stdlib.h>
#include "mruby.h"
#include "mruby/value.h"

static mrb_value
f_gpio_pinmode(mrb_state *mrb, mrb_value self)
{
  char buf[100], *dir_str;
  mrb_int pin, dir;
  mrb_get_args(mrb, "ii", &pin, &dir);

  if( dir==1 ){  // output
    dir_str = "output";
  } else {  // input
    dir_str = "input";
  }
  sprintf(buf, "set %s to port %d", dir_str, pin);  
  puts(buf);

  return mrb_nil_value();
}

static mrb_value
f_gpio_dwrite(mrb_state *mrb, mrb_value self)
{
  char buf[100], *val_str;
  mrb_int pin, value;
  mrb_get_args(mrb, "ii", &pin, &value);

  if( value == 0 ){
    val_str = "LOW";
  } else {
    val_str = "HIGH";
  }

  sprintf(buf, "output %s to port %d", val_str, pin);
  puts(buf);

  return mrb_nil_value();
}

static mrb_value
f_gpio_dread(mrb_state *mrb, mrb_value self)
{
  static int _val = 0;    /* dummy value */
  mrb_int pin;
  char buf[100];

  mrb_get_args(mrb, "i", &pin);

  sprintf(buf, "input from port %d", pin);

  _val = !_val;    /* dummy value */

  return mrb_fixnum_value(_val);
}

static mrb_value
f_gpio_awrite(mrb_state *mrb, mrb_value self)
{
  char buf[100], *val_str;
  mrb_int pin, value;
  mrb_get_args(mrb, "ii", &pin, &value);

  sprintf(buf, "output duty ratio %i to port %d", value, pin);
  puts(buf);

  return mrb_nil_value();
}

static mrb_value
f_gpio_aread(mrb_state *mrb, mrb_value self)
{
  static int _val = 0;    /* dummy value */
  mrb_int pin;
  char buf[100];

  mrb_get_args(mrb, "i", &pin);

  sprintf(buf, "input from port %d", pin);

  _val = !_val;    /* dummy value */

  return mrb_fixnum_value(_val);
}

void
mrb_mruby_gpio_emulation_gem_init(mrb_state* mrb)
{
  struct RClass *c;
  c = mrb_define_module(mrb, "Gpio");

  mrb_define_const(mrb, c, "OUTPUT", mrb_fixnum_value(1));
  mrb_define_const(mrb, c, "INPUT", mrb_fixnum_value(0));
  mrb_define_const(mrb, c, "HIGH", mrb_fixnum_value(1));
  mrb_define_const(mrb, c, "LOW", mrb_fixnum_value(0));

  mrb_define_module_function(mrb, c, "pinMode", f_gpio_pinmode, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, c, "digitalWrite", f_gpio_dwrite, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, c, "digitalRead", f_gpio_dread, MRB_ARGS_REQ(1));
  mrb_define_module_function(mrb, c, "analogWrite", f_gpio_awrite, MRB_ARGS_REQ(2));
  mrb_define_module_function(mrb, c, "analogRead", f_gpio_aread, MRB_ARGS_REQ(1));
}

void
mrb_mruby_gpio_emulation_gem_final(mrb_state* mrb)
{
}
