#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 2038

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 15, 0, 2, 4);

void setup()
{
   //myservo.attach(SERVO);
   Serial.begin(115200);
}

void loop()
{
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(10);
  // move a number of steps equal to the change in the
  stepper.step(2038);
  Serial.println("rotated ya bastard. now back");
  stepper.step(-2038);
  Serial.println("home at last");


}
