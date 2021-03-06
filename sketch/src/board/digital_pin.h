#ifndef digital_pin_h
#define digital_pin_h

#include "Arduino.h"
#include "pin.h"
#include "pin_mode.h"
#include "pin_value.h"

class DigitalPin : public Pin {

  PinMode _mode;
  PinValue _value;
  bool _pwm;

  public:
    DigitalPin(int);

    char* getMode();
    PinValue getValue();

    void setValue(PinValue);
    void setMode(char*);

    void reset();

};

#endif
