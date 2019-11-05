#include <Stepper.h>
#include <ESP32Servo.h> 

// change this to the number of steps on your motor
#define STEPS 2038
#define SERVO 14
#define PIEZO 12
#define TONGUE 13

Servo myservo;

int vib = 0;
int prevVib = 0;
int val = 0;

int eyes=0;
int jaw=0;



// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 15, 0, 2, 4);


void setup()
{
   myservo.attach(SERVO);

   pinMode(PIEZO, INPUT);
   pinMode(TONGUE, OUTPUT);

   Serial.begin(115200);

   myservo.write(eyes);
}

void loop()
{
  prevVib=vib;
  vib = analogRead(PIEZO);
  Serial.println("vibration reading: " + String(vib));

  if(vib-prevVib>100){
    val=vib;
    Serial.println("value read: " + String(val));
  }
  else{
    val=0;
  }

  if(val>0){
    eyes=constrain(val,0,1300);
    eyes = map(eyes,0, 1300, 0, 75);
    myservo.write(eyes);
    Serial.println("opening eyes " + String(eyes));
    delay(40 0);

    if(val>1300){
    jaw = constrain(val,1300, 2600);
    jaw=map(jaw,1300,2600,0, 350);
    stepper.setSpeed(10);
    Serial.println("Opening mouth " + String(jaw));
    stepper.step(jaw);
  }
  if(val>2600){
    digitalWrite(TONGUE, HIGH);
    Serial.println("tongue");
  }
  delay(2500);

  /////return to resting face
  digitalWrite(TONGUE, LOW);
  stepper.step(-jaw);
  myservo.write(0);
  delay(500);
  }
}
