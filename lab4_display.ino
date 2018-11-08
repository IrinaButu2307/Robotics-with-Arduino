#define PIN_A 2
#define PIN_B 3
#define PIN_C 4
#define PIN_D 5
#define PIN_E 6
#define PIN_F 7
#define PIN_G 8

#define SW_PIN 12 // digital pin connected to switch output
#define X_PIN A0 // analog pin connected to X output
#define Y_PIN A1 // analog pin connected to Y output

int segments[7] = {PIN_A, PIN_B, PIN_C, PIN_D, PIN_E, PIN_F, PIN_G};
void write_number(int);
int switch_value;
int x_value, y_value;
int count=0;

//int numbers[10][10]={{1,1,1,1,1,1,0}, {0,1,1,0,0,0,0}, {1,1,0,1,1,0,1}, {1,1,1,1,0,0,1}, {0,1,1,0,0,1,1}, {1,0,1,1,0,1,1}, {1,0,1,1,1,1,1}, {1,1,1,0,0,0,0},{1,1,1,1,1,1,1},{1,1,1,0,1,1,1}};

int numbers[10][7] = {
  {1,1,1,1,1,1,0},
  {0,1,1,0,0,0,0},
  {1,1,0,1,1,0,1},
  {1,1,1,1,0,0,1},
  {0,1,1,0,0,1,1},
  {1,0,1,1,0,1,1},
  {1,0,1,1,1,1,1},
  {1,1,1,0,0,0,0},
  {1,1,1,1,1,1,1},
  {1,1,1,1,0,1,1}
};
void write_number(int number) {
  for (int i = 0; i < 7; i++) {
  digitalWrite(segments[i],numbers[number][i]);
}
}
void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 7; i++) {
    pinMode(segments[i], OUTPUT);   //pt a nu scrie manual
  }
//joystick
  pinMode(SW_PIN, INPUT);
  digitalWrite(SW_PIN, HIGH);  
  Serial.begin(9600);

  
}

void loop() {
  
//  for (int i = 0; i < 10; i++) {
//  write_number(i);
//  delay(1000); } 
//    for (int i = 9; i >=0; i--) {
//  write_number(i);
//  delay(1000); 
//}
  

  switch_value = digitalRead(SW_PIN);
  x_value = analogRead(X_PIN);
  y_value = analogRead(Y_PIN);


 //if(x_value>=511 && y_value<=511)count--;
  Serial.print("Switch:  ");
  Serial.print(switch_value);
  Serial.print("\n");
  Serial.print("X-axis: ");
  Serial.print(x_value);
  Serial.print("\n");
  Serial.print("Y-axis: ");
  Serial.print(y_value);
  Serial.print("\n\n");
  delay(500);
Serial.print(count);

   if(x_value>=400 && y_value>=511)write_number(++count);
   if(x_value>=1000 )write_number(--count);

  

  

  
  
}



 
