#include <MsTimer2.h>        //timer2
#include <PinChangeInt.h>    //The pin external interruption library.All arduino UNO pins are available.
/***************************define L298P pin***************************/
const int right_R1=7;    
const int right_R2=8;
const int PWM_R=9;
const int left_L1=12;
const int left_L2=6;
const int PWM_L=10;
/**************************Interrupt speed count***********************/
#define Hall_left 2             //interrupt pin
#define Direction_left 5
#define Hall_right 3            //interrupt pin
#define Direction_right 4
volatile long count_right = 0;  
volatile long count_left = 0;
//////////////////////////setup function//////////////////////////////
void setup() {
  pinMode(right_R1,OUTPUT);      //motor control pin     
  pinMode(right_R2,OUTPUT);
  pinMode(left_L1,OUTPUT);
  pinMode(left_L2,OUTPUT);
  pinMode(PWM_R,OUTPUT);
  pinMode(PWM_L,OUTPUT);
  pinMode(Hall_left, INPUT);     //hall pin
  pinMode(Direction_left,INPUT);
  pinMode(Hall_right, INPUT);
  pinMode(Direction_right,INPUT);
  Serial.begin(9600);                       //Opening a serial port,Set the baud rate to 9600
  MsTimer2::set(2000, time2_interrupt);      //The time2_interruptfunction is executed once by 2000ms
  MsTimer2::start();                         //Open the interrupt
  attachPinChangeInterrupt(Hall_left, Encoder_left, CHANGE);          //define interrupt function
  attachPinChangeInterrupt(Hall_right, Encoder_right, CHANGE);        //define interrupt function
}
//////////////////////////loop function//////////////////////////////
void loop() { 
  digitalWrite(left_L1,LOW);
  digitalWrite(left_L2,HIGH);
  analogWrite(PWM_L,160);
  digitalWrite(right_R1,LOW);
  digitalWrite(right_R2,HIGH);
  analogWrite(PWM_R,160);
  delay(2000);
  digitalWrite(left_L1,HIGH);
  digitalWrite(left_L2,LOW);
  analogWrite(PWM_L,80);
  digitalWrite(right_R1,HIGH);
  digitalWrite(right_R2,LOW);
  analogWrite(PWM_R,80);
  delay(2000);
}
//////////////////////time2_interrupt function////////////////////////
void time2_interrupt(void){
  Serial.print("left_motor speed:");
  Serial.println(count_left);
  Serial.print("right_motor speed:");
  Serial.println(count_right);
  Serial.println("");
  count_left=count_right=0;
}
///////////////////////hall of the left motor/////////////////////////
void Encoder_left() {
  if(digitalRead(Hall_left)==LOW){
    if(digitalRead(Direction_left)==LOW){count_left ++;}
    else {count_left --;}
    }
  else{
    if(digitalRead(Direction_left)==LOW){count_left --;}
    else {count_left ++;}
    }
} 
///////////////////////hall of the right motor/////////////////////////
void Encoder_right() {
  if(digitalRead(Hall_right)==LOW){
    if(digitalRead(Direction_right)==LOW){count_right --;}
    else {count_right ++;}
    }
  else{
    if(digitalRead(Direction_right)==LOW){count_right ++;}
    else {count_right --;}
    }
} 
