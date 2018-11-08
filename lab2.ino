
#define LED 11
int potPin=A0;
int val=0;
int valMap=0;
void setup() {
  // put your setup code here, to run once:
pinMode(13,OUTPUT); 

Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(LED, HIGH);
  //delay(100);
  //digitalWrite(LED, LOW);
  //delay(100 );
  val=analogRead(potPin);
  Serial.println(val);
  valMap=map(val,0,1024,0,255);
  analogWrite(LED, valMap);
  
}
