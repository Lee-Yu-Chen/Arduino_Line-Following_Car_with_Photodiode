int echo=13;
int trig=12;
int led1=A1;
int led2=2;

int ENA=3;
int ENB=11;
int IN1=A2;
int IN2=A3;
int IN3=A4;
int IN4=A5;

float distance;
float duration;

int sp=70;
int turn=80;
int r=7;  // right wheel is moving slower than left wheel so I add a little value to right wheel speed

int i,i1;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trig,OUTPUT);
pinMode(echo,INPUT);

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

digitalWrite(trig,LOW);   
delayMicroseconds(2);  


digitalWrite(trig,HIGH);  
delayMicroseconds(10);  
digitalWrite(trig,LOW); 


duration = pulseIn(echo,HIGH);  


distance = duration/58;  

/*
Serial.println(distance);
*/

if (distance<=15){
digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);

  for(i=0;i<=7;i++){

    if(i%2==0){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    }
    else if(i%2==1){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    }
    delay(100);
    }
   
i1=0;
    while(distance<=15){

if(i1%2==0){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    }
    else if(i1%2==1){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    }
      
  digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,1);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);
  delay(200);

  digitalWrite(trig,HIGH);  
delayMicroseconds(10);  
digitalWrite(trig,LOW); 


duration = pulseIn(echo,HIGH);  


distance = duration/58;  
i1++;
      }
   digitalWrite(led1,0);
    digitalWrite(led2,0);
    
  }


  
else{
   digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,sp);
  analogWrite(ENB,sp+r);
  }



}
