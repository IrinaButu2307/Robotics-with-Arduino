#define LED 13
#define buton 2
int x;
void setup() {
  // put your setup code here, to run once:
 pinMode(LED, OUTPUT);
 pinMode(buton, INPUT);
 Serial.begin(9600); //pt a face output la consola 
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(buton);
  Serial.println(x);
  int count=0;
  if(x %2== 0)
    //digitalWrite(LED, HIGH);
    //else
   // digitalWrite(LED, LOW);
  {
    digitalWrite(LED, HIGH);
    delay(150);
  }
  else
  {
    digitalWrite(LED, HIGH);
    delay(150);
  }
}
