

#define BUTTON_PIN 2   // the number of the pushbutton pin
#define LED_PIN 13             // the number of the LED pin

// variables will change:

int ledState = LOW;       // the current state of the output pin
int buttonState;          // the current reading from the input pin
int lastButtonState = LOW;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50; // the debounce time; increase if the output flickers

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
 
  int reading = digitalRead(BUTTON_PIN);  //citesc valoarea butonului
  Serial.println(reading);

  if (reading != lastButtonState)       //verific daca s-a schimbat fata de ultima val
  {
  lastDebounceTime = millis();        //resetez timerul pt debounce
  }

  if ((millis() - lastDebounceTime) > debounceDelay)  //daca a trecut timpul setat in debounceDelay, daca schimbarea nu e de fapt doar "scantei" de curent
  {
  if (reading != buttonState)     // si daca noua stare e diferita de cea salvata in buttonState
  {
        buttonState = reading;        //actualizez buttonState

        if (buttonState == HIGH)      //starea s-a schimbat si butonul e apasat => schimb starea ledului
        {
            ledState = !ledState;
        }
  }
  }

  digitalWrite(LED_PIN, ledState);  //aprind/string led-ul in functie de starea salvata

  lastButtonState = reading;        //actualizez lastButtonState
}
