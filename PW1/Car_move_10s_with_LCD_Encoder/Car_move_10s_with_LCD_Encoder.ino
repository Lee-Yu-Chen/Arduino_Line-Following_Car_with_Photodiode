#include <LiquidCrystal.h>
LiquidCrystal lcd(8,9,4,5,6,7);
int IN1=A1;
int IN2=A2;
int IN3=A3;
int IN4=A4;
int EnA=11;
int EnB=3;
int encl=13;
int encr=12;

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
pinMode(encr,INPUT);
pinMode(encl,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(EnA,128);
  analogWrite(EnB,128);

int i=0;
int n=0;
digitalWrite(IN1,1);
digitalWrite(IN2,0);
digitalWrite(IN3,1);
digitalWrite(IN4,0);
while (i!=10000){
  i++;
  int t1=digitalRead(encr);
  delay(1);
  int t2=digitalRead(encr);
  if (t1==1 & t2==0){
    n++;
    }
  else{
    n=n;
  }
  if (i%1000==0){
    lcd.clear();
    lcd.setCursor(3,0);
    lcd.print(int(i/1000));
    }
  else{
    i=i;
    }
  }
  digitalWrite(IN1,0);
  digitalWrite(IN3,0);
  float d=n/20*0.215;
  lcd.setCursor(2,1);
  lcd.print("d=");
  lcd.print(d);
  lcd.print("m");
  delay(20000);
}
