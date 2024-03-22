#include <LiquidCrystal.h>

LiquidCrystal lcd(8,9,4,5,6,7);

int IRl=A1;
int IRr=A2;
int IRa=13;
int ENA=3;
int ENB=11;
int IN1=A3;
int IN2=A4;
int IN3=A5;
int IN4=2;


//380/390,100,10
//380,120,30
//360/370,120,5
//390,100,25
//390,110,30


int fast=390;//
int turn=110;
int rev=30;//10


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2);
pinMode(IRl,INPUT);
pinMode(IRr,INPUT);
pinMode(IRa,INPUT);
pinMode(ENA,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
}

void loop() {
  int t0=millis();
   lcd.setCursor(3,0);
        lcd.print(0);
  
  // put your main code here, to run repeatedly:
  //left IR white high black low
  //right IR white low black high
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,fast);
  analogWrite(ENB,fast);
  delay(2);

  int left=analogRead(IRl);
  int right=analogRead(IRr);
  int assist=digitalRead(IRa);

    //stop if both touch black line(end)
    //while right==white or left==white
    //not(left==black && right==black)
   unsigned long int tn;
    unsigned long int ti;
    unsigned long int ti1;
    unsigned int ts=0;
  while(left>=300 || right<=250 || assist==0){

    //left black, right white
    if (left<300 && right<=250){
      digitalWrite(IN1,0);
      digitalWrite(IN2,1);
      digitalWrite(IN3,1);
      digitalWrite(IN4,0);
      analogWrite(ENA,fast+rev);
      analogWrite(ENB,fast+turn);
     
      
      }

      //left white, right black
    else if(left>=300 && right>250){
      digitalWrite(IN1,1);
      digitalWrite(IN2,0);
      digitalWrite(IN3,0);
      digitalWrite(IN4,1);
      analogWrite(ENA,fast+turn);
      analogWrite(ENB,fast+rev);
      
  }

  //left white, right white
    else if(left>=300 && right<=250){
       digitalWrite(IN1,1);
       digitalWrite(IN2,0);
       digitalWrite(IN3,1);
       digitalWrite(IN4,0);
       analogWrite(ENA,fast);
      analogWrite(ENB,fast);
      
  }
  //left black, right black, look at assist
  else if (left<300 && right>250 && assist==0){
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
       

       tn=millis();
       ti1=ti;
       ti=tn-t0;
       
       
     
        if ((ti/1000)>(ti1/1000)){
          ts=ti/1000;

        lcd.clear();
        lcd.setCursor(3,0);
        lcd.print(ts);
        
          }
        else{}
        
        
        
       
       
      
  left=analogRead(IRl);
  right=analogRead(IRr);
  assist=digitalRead(IRa);
    }

   

    
    //stop at end
  digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);



while(ti>=1000){
  ti-=1000;
  }


lcd.clear();
lcd.setCursor(2,0);
lcd.print("Time taken: ");
lcd.setCursor(4,1);
lcd.print(ts);
lcd.print(".");
lcd.print(ti);
lcd.print("s");


   

  
  while(1){
    }
}
