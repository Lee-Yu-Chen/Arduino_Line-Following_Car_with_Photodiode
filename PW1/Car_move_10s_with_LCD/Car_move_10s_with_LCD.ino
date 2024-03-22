#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
 //Parameters : lcd(RS,Enable,D4,D5,D6,D7)
int IN1=A1;
int IN2=A2;
int IN3=A3;
int IN4=A4;
int EnA=11;
int EnB=3;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode(EnA,OUTPUT);
pinMode(EnB,OUTPUT);
}
int t;
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(EnA,128);
  analogWrite(EnB,128);
  for(t=1;t<=10;t++){
lcd.setCursor(3,0);
lcd.print(t);
digitalWrite(IN1,1);
digitalWrite(IN2,0);
digitalWrite(IN3,1);
digitalWrite(IN4,0);
delay(1000);
lcd.clear();

  }
  digitalWrite(IN1,0);
digitalWrite(IN3,0);

delay(20000);
}
