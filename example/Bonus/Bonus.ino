/*
 Bonus_1
 Congratulations! You have found our secret sketch. Upload
 it to the robot and see the magic.
 
 This is an example from the Svante robot summer camp.

 (c) 2014 Arduino LLC
*/
#include <Svante.h>
#include <EEPROM.h>

int ir_leds[] ={IR_1, IR_2, IR_3};
int delayTime = 100;

// the setup routine runs once when you press reset:
void setup() {              
  for(int i=0; i<3; i++)  pinMode(ir_leds[i], OUTPUT);    
}

// the loop routine runs over and over again forever:
void loop() {
  for(int i=0; i<3; i++){
    digitalWrite(ir_leds[i], HIGH);
    delay(delayTime);
  }
  for(int i=2; i>=0; i--){
    digitalWrite(ir_leds[i], LOW);
    delay(delayTime);
  }
  for(int i=2; i>=0; i--){
    digitalWrite(ir_leds[i], HIGH);
    delay(delayTime);
  }
  for(int i=0; i<3; i++){
    digitalWrite(ir_leds[i], LOW);
    delay(delayTime);
  }

}
