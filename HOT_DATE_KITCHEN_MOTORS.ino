#include <Servo.h>
#include <ezButton.h>

//speed control
int speed_drive = 0;
int stop_button = 8;
int position_button = 4;
int position_button_state = HIGH;
int drive_potentiometer = A0;
int brush_potentiometer = A1;
int PWMvalue_drive = speed_drive * 5 + 1500; //scale up to 1000-2000
int speed_brush;
int PWMvalue_brush = speed_brush * 5 + 1500; //scale up to 1000-2000
int stop_value = 1500;
int loading_time = 5000;


//LED pins
int green_led = 8;
int yellow_led = 9;
int red_led = 10;
int e_stop = 13;

//Servo intializers
Servo brush;
Servo drive;
int brush_pin = 6;
int drive_pin = 5;

void setup() {
 Serial.begin(9600);
 pinMode(position_button, INPUT_PULLUP);
 pinMode(e_stop, INPUT_PULLUP);
 pinMode(stop_button, INPUT_PULLUP);
 pinMode(green_led, OUTPUT);
 pinMode(yellow_led, OUTPUT);
 pinMode(red_led, OUTPUT);

 brush.attach(brush_pin); //associate the object to a pin
 drive.attach(drive_pin); //associate the object to a pin


}

         
void loop() {
Serial.println(digitalRead(e_stop));
int drive_sensorValue = analogRead(drive_potentiometer);
int speed_drive = drive_sensorValue * -.0977;
int PWMvalue_drive = speed_drive * 5 + 1500; //scale up to 1000-2000
int brush_sensorValue = analogRead(brush_potentiometer);
int speed_brush = brush_sensorValue * -.0977;
int PWMvalue_brush = speed_brush * 5 + 1500; //scale up to 1000-2000
position_button_state = digitalRead(position_button);

  if(position_button_state == LOW){
     brush.writeMicroseconds(PWMvalue_brush);
     drive.writeMicroseconds(stop_value);
     digitalWrite(green_led, LOW);
     digitalWrite(red_led, HIGH);
     delay(loading_time);
     digitalWrite(red_led, LOW);
     digitalWrite(green_led, HIGH);
     brush.writeMicroseconds(stop_value);
     drive.writeMicroseconds(PWMvalue_drive);
  }else{
     drive.writeMicroseconds(PWMvalue_drive);
     brush.writeMicroseconds(stop_value);
  }
  if (speed_drive == 0) {
     digitalWrite(red_led, HIGH);
     digitalWrite(green_led, LOW);
  }
  else{
     digitalWrite(green_led, HIGH);
     digitalWrite(red_led, LOW);
  }
  
  if (digitalRead(e_stop) == LOW) {
    digitalWrite(yellow_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(red_led, LOW);
 
  }else{
    digitalWrite(yellow_led, LOW);

  }
}
      

   
