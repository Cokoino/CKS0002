void setup(){           //Set parameter function
pinMode(6, OUTPUT);    //Set pin6 to output mode
pinMode(7, OUTPUT);    //Set pin7 to output mode
pinMode(8, OUTPUT);    //Set pin8 to output mode
pinMode(9, OUTPUT);    //Set pin9 to output mode
pinMode(10, OUTPUT);   //Set pin10 to output mode
pinMode(12, OUTPUT);   //Set pin12 to output mode
}
void loop(){            //The main loop function
analogWrite(10,200);    //pin10 output duty ratio of 200:55 of the PWM signal
digitalWrite(12,HIGH);  //pin12 output high level
digitalWrite(6,LOW);    //pin6 output low level

analogWrite(9,200);     //pin9 output duty ratio of 200:55 of the PWM signal
digitalWrite(8,HIGH);   //pin2 output high level
digitalWrite(7,LOW);    //pin7 output low level
delay(2000);            //delay 2000ms

analogWrite(10,200);    //pin10 output duty ratio of 200:55 of the PWM signal
digitalWrite(12,LOW);   //pin12 output low level
digitalWrite(6,HIGH);   //pin6 output high level

analogWrite(9,200);     //pin9 output duty ratio of 200:55 of the PWM signal
digitalWrite(8,LOW);    //pin8 output low level
digitalWrite(7,HIGH);   //pin7 output high level
delay(2000);            //delay 2000ms
}
