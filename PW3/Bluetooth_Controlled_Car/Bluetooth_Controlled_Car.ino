#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);
int s;
int s1;
int x;
int i;

int IRl=A1;
int IRr=2;

int ENA=3;
int ENB=11;
int IN1=A2;
int IN2=A3;
int IN3=A4;
int IN4=A5;

int led1=12;
int led2=13;


int fast=100;
int tur=50;
int rev=20;

int sp=100;
int turn=80;

void setup() {
  
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

pinMode(led1,OUTPUT);
pinMode(led2,OUTPUT);

}

void loop() {
 
 
 s1=s;
 s=Serial.read();

     //'g' stand for go
    if (s=='g'){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,sp);
  analogWrite(ENB,sp);
      }

      //'l' stand for left
    else if(s=='l'){
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);
      }

      //'r' stand for right
    else if(s=='r'){
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);
      }

      //'R' stand for reverse
    else if(s=='R'){ 
  digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  analogWrite(ENA,sp);
  analogWrite(ENB,sp);
  }

    //rotate left
  else if(s=='p'){
     digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);

  }

    //rotate right
  else if(s=='q'){
     digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);
    }

      //'f' stand for faster
    else if(s=='f'){
      sp+=10;
      turn+=10;
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Speed : ");
      lcd.setCursor(4,1);
      lcd.print(sp);
      lcd.print("  ");
      lcd.print(turn);
      }

        //'s' stand for slower
      else if(s=='s'){
      sp-=10;
      turn-=10;
      lcd.clear();
      lcd.setCursor(2,0);
      lcd.print("Speed : ");
      lcd.setCursor(4,1);
      lcd.print(sp);
      lcd.print("  ");
      lcd.print(turn);
      }

         //switch on led, press once more to switch off. Will light up in two difference colour in turns
      else if (s=='e' && s1!='e'){
        x=0;
         while(x!='e'){
           if (i%2==0){
          digitalWrite(led1,1);
          digitalWrite(led2,0);
          }
        else if(i%2==1){
           digitalWrite(led1,0);
          digitalWrite(led2,1);
          }
         
          delay(100);
          x=Serial.read();
          }
           digitalWrite(led1,0);
          digitalWrite(led2,0);
          i++;
         
        }

        //double tab the button, enable led blinking in two colours. Press once more to stop blinking
      else if(s=='e' && s1=='e'){
        x=0;
        while(x!='e'){
          digitalWrite(led1,1);
          digitalWrite(led2,0);
          delay(200);
          digitalWrite(led1,0);
          digitalWrite(led2,1);
          delay(200);
          x=Serial.read();
          }
          digitalWrite(led1,0);
          digitalWrite(led2,0);
        }

        //'t' stand for track, press once more to stop 
      else if(s=='t'){

  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  delay(2);

  int left=analogRead(IRl);
  int right=digitalRead(IRr);

      x=0;
  while((left>=450 || right==0)&& x!='t'){
        if (left<450 && right==0){
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      analogWrite(ENA,fast+rev);
      analogWrite(ENB,fast+tur);     
      }

      //left white, right black
    else if(left>=450 && right==1){
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      analogWrite(ENA,fast+tur);
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

        left=analogRead(IRl);
  right=digitalRead(IRr);
  x=Serial.read();
  }
        }
      
    else{
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);
      
    }
  
delay(200);
}
