#include <MsTimer2.h>        //timer2
const int buzzer=11;         //define buzzer pin  
//////////////////////time2_interrupt function////////////////////////
void buzzer_run(void){
  static boolean output = HIGH;
  digitalWrite(buzzer,output);
  output=!output;
}
//////////////////////////setup function//////////////////////////////
void setup() {
  /*buzzer pin*/
  pinMode(buzzer, OUTPUT);  

  MsTimer2::set(3, buzzer_run);  //The time2_interruptfunction is executed once by 2000ms
  MsTimer2::start();             //Open the interrupt
}
//////////////////////////loop function//////////////////////////////
void loop() { 
//Wait for interrupt program
}
