#ifndef board_h
#define board_h

#include "pin.h"

#define PIN_COUNT (NUM_DIGITAL_PINS - NUM_ANALOG_INPUTS)

class Board {

  static Board* _instance;
  Pin* _pins[PIN_COUNT];

  public:
    Pin* getPin(int);
    void reset();

    static Board* getInstance();

  private:
    Board();
    ~Board();
  
};

#endif
