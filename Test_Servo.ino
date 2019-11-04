#include <ESP32Servo.h> 
#define SERVO 14
Servo myservo;

int pos =0;

void setup() {
  myservo.attach(SERVO);  
  Serial.begin(115200);

}

void loop() {
  if(pos>=180){
    pos=0;
  }
  myservo.write(pos);
  Serial.println(String(pos));
  pos +=10;
  delay(1000);
  myservo.write(0);
  delay(1000);
}
