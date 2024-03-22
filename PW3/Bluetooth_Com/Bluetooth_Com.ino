
String s;


void setup() {
  
  Serial.begin(9600);

}

void loop() {
 
  s=Serial.readStringUntil('\n');
    

    Serial.print(Serial.available());
   Serial.print("\t");
    Serial.print(s);
     Serial.print("\t");
     Serial.println(s==NULL);
     //Serial.readStringUntil()==NULL if not key-in anything


}
