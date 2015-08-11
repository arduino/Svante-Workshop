#include <SVremote.h>
#include <SVremoteTools.h>
/*
*  Demo for TinkerKitSVremote
*  Make sure you are using TinkerKit remote,
*  connect a IR receiver to pin 13 (It's recommanded
*  to use a Tsop2238)
*  When you press a button on the remote, it 
*  displays the signal.
*  When you release the button, it display an end
*  signal.
*  
*  By Xun Yang 2014
*  Forked from shirriff/Arduino-SVremote
*  This crap is opensource
*  etc etc
*
*/
const int RECV_PIN = 13;  //Define the receiver pin
const unsigned long TIMER_MAX=200;  //Timeout for when no repeat frame is received

boolean pressed=false;
unsigned long IRtimer=0;	//Timer for keep pressed key

void setup(){
  Serial.begin(9600);
  beginSVremote(RECV_PIN);  //Initialze the remote
  IRtimer=millis();

}
void loop(){
  if(SVreceived()){  //if a signal is received 
    unsigned long command=getSVresult();  //decode the signal
    IRtimer=millis();
    pressed=true;
    
    //Do you stuff here
    doStuff(command);
    
    resumeSVremote();  //resume the receiver
  }
  
  if(pressed && millis()-IRtimer>TIMER_MAX){
    pressed=false;
    Serial.println("end");
  }
}

void doStuff(unsigned long command){
  switch(command){
    case REMOTE_UP:
      Serial.println("forward");
      break;
    case REMOTE_DOWN:
      Serial.println("backwards");
      break;
    case REMOTE_LEFT:
      Serial.println("left");
      break;
    case REMOTE_RIGHT:
      Serial.println("right");
      break;
    case REMOTE_MIDDLE:
      Serial.println("middle");
      break;
    case REMOTE_MINUS:
      Serial.println("minus");
      break;
    case REMOTE_PLUS:
      Serial.println("plus");
      break;
  }

}
