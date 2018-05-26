#include <Servo.h>


// constants won't change. They're used here to set pin numbers:
const int ledPin = 12;   // The pin used for LED is 12
const int buttonPin = 2; // The pin for the button is 6
const int BatteryLED = 13; //Pin used to keep battery pack awake

Servo myservo;  // create servo object

// variables will change:
int pos = 70;    // store servo position
int buttonState = 0;         // variable for reading the pushbutton status
int incrementing = true;         // variable for deciding whether to increment or not

void setup() {
  myservo.attach(9);  // attach servo pin to Pin9

  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  
  // initialize digital pin BatteryLED as an output.
  pinMode(BatteryLED, OUTPUT);
}

void loop() {  
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    digitalWrite(BatteryLED, HIGH);
  }   
   if (buttonState == HIGH) {
    // If the position is 40, turn incrementing on. Otherwise turn it off.
    if (pos == 40) incrementing = true;
    if (pos == 100) incrementing = false;

    // Either increase or decrease value as desired
    if (incrementing) {
      pos += 1;
    }
    else {
      
      pos -= 1;
    }

    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(7);                       // 7ms for the servo to reach the position
  }
}

