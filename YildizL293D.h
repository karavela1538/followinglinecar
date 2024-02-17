#ifndef YildizL293D_h
#define YildizL293D_h

#include "Arduino.h"

class YildizL293D {
    public:
        YildizL293D(int pin1, int pin2, int pin3, int pin4);
        void motor(String direction);

    private:
        int _motorPin1, _motorPin2, _motorPin3, _motorPin4;
};

#endif

