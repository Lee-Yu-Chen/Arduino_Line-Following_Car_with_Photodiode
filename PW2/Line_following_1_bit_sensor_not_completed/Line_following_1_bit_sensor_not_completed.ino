#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);

int in1=A2;
int in2=A3;
int in3=A4;
int in4=A5;
int EnA=3;
int EnB=11;
int IR=A1;
int fast=90;
int slow=60;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(EnA,OUTPUT);
  pinMode(EnB,OUTPUT);
  pinMode(IR,INPUT);
  
  

}
int t;
int i;
int s;


void loop() {
  digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(EnA,slow);
  analogWrite(EnB,slow);


  while(1){
    s=analogRead(IR);
    if(s>200){
      digitalWrite(in1,0);
  digitalWrite(in2,1);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(EnA,slow);
  analogWrite(EnB,slow);
  
      }
      else{
        
        int h=0;
        
        while(not(s>200)){
          h++;
          if(h%2==0){
           
  digitalWrite(in1,0);
  digitalWrite(in2,0);
  digitalWrite(in3,0);
  digitalWrite(in4,1);
  analogWrite(EnA,fast);
  analogWrite(EnB,fast);
 
      delay(h*50);
       s=analogRead(IR);
            }
          else{
            digitalWrite(in1,0);
            digitalWrite(in2,1);
            digitalWrite(in3,0);
            digitalWrite(in4,0);
            analogWrite(EnA,fast);
            analogWrite(EnB,fast);
      delay(h*50);
       s=analogRead(IR);
       }
          
          }
        }
    }
 delay(20000);
}
