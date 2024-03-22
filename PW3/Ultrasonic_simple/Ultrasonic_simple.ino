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

int sp=65;
int turn=sp+20;

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
Serial.print("Distance:");
Serial.println(distance);
*/

if (distance<=15){
digitalWrite(IN1,0);
  digitalWrite(IN2,0);
  digitalWrite(IN3,0);
  digitalWrite(IN4,0);

  for(i=0;i<=5;i++){

    if(i%2==0){
    digitalWrite(led1,0);
    digitalWrite(led2,1);
    }
    else if(i%2==1){
    digitalWrite(led1,1);
    digitalWrite(led2,0);
    }
    delay(200);
    }
    digitalWrite(led1,0);
    digitalWrite(led2,0);


   
    digitalWrite(IN1,0);
  digitalWrite(IN2,1);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,turn);
  analogWrite(ENB,turn);
delay(400);
  
  }


  
else{
   digitalWrite(IN1,1);
  digitalWrite(IN2,0);
  digitalWrite(IN3,1);
  digitalWrite(IN4,0);
  analogWrite(ENA,sp);
  analogWrite(ENB,sp);
  }



}
