//github setup
#include <SPI.h>
#include <Servo.h> //This comes with the Arduino

int talon_pin = 3;

Servo talon;
void setup() {
  // put your setup code here, to run once:
  int talon_max_forward = 180; //this might not actually be forward
int talon_max_reverse = 00; //this might not actually be reverse
int talon_stop = 90; //this is definitely stop (if the Talon is calibrated right)

}

void loop() {
  // put your main code here, to run repeatedly:
alon.write(talon_max_forward); //full power one way
delay(2000); //wait 2 seconds
talon.write(talon_stop); //full power the other way
delay(2000); //wait 2 seconds
talon.write(talon_max_reverse); //full power one way
delay(2000); //wait 2 seconds
talon.write(talon_stop); //full power the other way
delay(2000); //wait 2 seconds
}

