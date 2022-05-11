const int buttonPin = 7;     // the number of the pushbutton pin
unsigned long startTime;
unsigned long endTime;
unsigned long latency;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(115200);
  //pinMode(buttonPin, INPUT);
  Serial.println("Start");
  DDRD = DDRD & B10111111;
}

void loop() {
 
  buttonState = digitalRead(buttonPin);
  while(digitalRead(buttonPin) == HIGH) {}

  startTime = micros();

//  if (buttonState == HIGH) {
    // turn LED on:
//  }
 // else {
 //   // turn LED off:
  while(ACSR & B00100000){}
  endTime = micros();
 
  while((ACSR & B00100000) == 0){Serial.println("LIGHT");}
  while(digitalRead(buttonPin) == LOW){}
   

    
 // }
  latency = endTime - startTime;
   Serial.println("buttonState");
  Serial.println(latency);
  Serial.println(PIND);
}
