#include "YildizL293D.h"

YildizL293D::YildizL293D(int pin1, int pin2, int pin3, int pin4) {
    _motorPin1 = pin1;
    _motorPin2 = pin2;
    _motorPin3 = pin3;
    _motorPin4 = pin4;
    pinMode(_motorPin1, OUTPUT);
    pinMode(_motorPin2, OUTPUT);
    pinMode(_motorPin3, OUTPUT);
    pinMode(_motorPin4, OUTPUT);
}

void YildizL293D::motor(String direction) {
    // Tüm pinleri düþük yap
    digitalWrite(_motorPin1, LOW);
    digitalWrite(_motorPin2, LOW);
    digitalWrite(_motorPin3, LOW);
    digitalWrite(_motorPin4, LOW);

    // Yön kontrolü
    if (direction == "back") {
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin3, HIGH);
    } else if (direction == "forward") {
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin4, HIGH);
    } else if (direction == "right") {
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin4, HIGH);
    } else if (direction == "left") {
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin2, HIGH);
    } else if (direction == "brake") {
        // Fren için tüm pinleri yüksek yap
        digitalWrite(_motorPin1, HIGH);
        digitalWrite(_motorPin2, HIGH);
        digitalWrite(_motorPin3, HIGH);
        digitalWrite(_motorPin4, HIGH);
    }
    // "stop" komutu için ekstra bir koþul eklemeye gerek yok,
    // çünkü tüm pinler zaten baþta düþük yapýlýyor.
}

