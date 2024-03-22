
int IN1=12;
int IN2=11;
int IN3=3;
int IN4=2;
int EnA=5;
int EnB=6;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

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

digitalWrite(IN1,1);
digitalWrite(IN2,0);
digitalWrite(IN3,1);
digitalWrite(IN4,0);

delay(1000);

  }
  digitalWrite(IN1,0);
digitalWrite(IN3,0);
delay(20000);
}
