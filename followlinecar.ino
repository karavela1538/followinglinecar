#include <YildizL293D.h>
YildizL293D motor(2, 10, 4, 5); // Motor pinleri

const int leftSensorPin = 6;
const int centerSensorPin = 9;
const int rightSensorPin = A0;

void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);

  Serial.begin(9600); 

}

void loop() {
  followLine(); 

}

void followLine() {
  // Sensörlerden okunan değerler
  bool isLeftOnLine = digitalRead(leftSensorPin);
  bool isCenterOnLine = digitalRead(centerSensorPin);
  bool isRightOnLine = digitalRead(rightSensorPin);

  Serial.print("Sol Sensör Değeri: ");
  Serial.print(isLeftOnLine);
  Serial.print(" - Orta Sensör Değeri: ");
  Serial.print(isCenterOnLine);
  Serial.print(" - Sağ Sensör Değeri: ");
  Serial.println(isRightOnLine);
  
  if (isLeftOnLine==0 && isCenterOnLine==1 && isRightOnLine==0) {
    // Çizgi merkezdeyse:
     motor.motor("forward");
  } else if (isLeftOnLine==1 && isCenterOnLine==0 && isRightOnLine==0) {
    // Çizgi solundaysa:
     motor.motor("left");
  } else if (isLeftOnLine==0 && isCenterOnLine==0 && isRightOnLine==1) {
    // Çizgi sağındaysa:
     motor.motor("right");
  } else {
    // Çizgi izleme durumu dışındaysa:
    motor.motor("brake");
  }
}