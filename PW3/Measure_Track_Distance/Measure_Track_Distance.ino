#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int IRl=A1;
int IRr=2;

int ENA=3;
int ENB=11;
int IN1=A2;
int IN2=A3;
int IN3=A4;
int IN4=A5;

int encl=13;
int encr=12;




//500,85,40,20
//250,85,40,20
int fast=100;
int turn=40;
int rev=20;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
pinMode(IRl,INPUT);
pinMode(IRr,INPUT);

pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);

pinMode(encl,INPUT);
pinMode(encr,INPUT);
}

void loop() {
 
  

  
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  delay(2);

  int left=analogRead(IRl);
  int right=digitalRead(IRr);
  int Ls,Rs; //left state, right state
  int Ls1,Rs1;
  unsigned long int Lc=0,Rc=0; //left count, right count. Necessary to put =0, otherwise will start at a large value
  float Ld,Rd,distance; //left distance, right distance

    //left white high black low
    //right white 0, black 1 
  while(left>=450 || right==0){
    Ls1=Ls;
    Rs1=Rs;
    Ls=digitalRead(encl);
    Rs=digitalRead(encr);

    //left black, right white
    if (left<450 && right==0){
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      analogWrite(ENA,fast+rev);
      analogWrite(ENB,fast+turn);
     
      
      }

      //left white, right black
    else if(left>=450 && right==1){
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      analogWrite(ENA,fast+turn);
      analogWrite(ENB,fast+rev);
      
  }

  //left white, right white
    else if(left>=450 && right==0){
       digitalWrite(IN1,1);
       digitalWrite(IN2,0);
       digitalWrite(IN3,1);
       digitalWrite(IN4,0);
       analogWrite(ENA,fast);
      analogWrite(ENB,fast);
      
  }  
      delayMicroseconds(250);
       digitalWrite(IN1,0);
       digitalWrite(IN2,0);
       digitalWrite(IN3,0);
       digitalWrite(IN4,0);
       
   if (Rs1==1 && Rs==0){
    Rc++;
    }
   else{}
   if(Ls1==1 && Ls==0){
    Lc++;
    }
   else{}
   
  left=analogRead(IRl);
  right=digitalRead(IRr);


 
    }

   

    
    //stop at end
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);


//20 gaps in one round 
//circumference of wheel: 21.5 cm /0.215m


Ld=Lc/20*0.215;  //left distance
Rd=Rc/20*0.215;  //right distance

distance=(Rd+Ld)/2;  // distance = average between left and right


//print distance
lcd.clear();
lcd.setCursor(2,0);
lcd.print("Distance : ");
lcd.setCursor(4,1);
lcd.print(distance);
lcd.print(" m");


  //stop moving
  while(1){
    }
}
