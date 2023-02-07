// constants won't change
const int BUTTON_PIN = 7;  // Connect the Button to pin 7 or change here
const int LED_PIN3    = 3;       // Connect the LED to pin 3 or change here
const int LED_PIN2    = 2;       // Connect the LED to pin 2 or change here

  
// variables will change:
int ledState3 = LOW;        // tracks the current state of LED3
int ledState2 = HIGH;        // tracks the current state of LED2
int lastButtonState3;        // the previous state of button
int currentButtonState3; // the current state of button
int lastButtonState2;        // the previous state of button
int currentButtonState2; // the current state of button
  
void setup() {
  Serial.begin(9600);                         // initialize serial
  pinMode(BUTTON_PIN, INPUT);  // set arduino pin to input mode
  pinMode(LED_PIN3, OUTPUT);      // set arduino pin to output mode
  pinMode(LED_PIN2, OUTPUT);      // set arduino pin to output mode
  
  currentButtonState3 = digitalRead(BUTTON_PIN);
  currentButtonState2 = digitalRead(BUTTON_PIN);
}
  
void loop() {
  lastButtonState3    = currentButtonState3;                // save the last state
  currentButtonState3 = digitalRead(BUTTON_PIN); // read new state
  
  if(lastButtonState3 == HIGH && currentButtonState3 == LOW) {
    Serial.print("The button is pressed: ");
  
    // toggle state of LED3
    if(ledState3 == LOW) {
       ledState3 = HIGH;  
       Serial.println("Turning LED3 on");
    }
    else {
      ledState3 = LOW;
      Serial.println("Turning LED3 off");
    }
 
    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN3, ledState3);  //turns the LED on or off based on the variable
  }



  lastButtonState2    = currentButtonState2;                // save the last state
  currentButtonState2 = digitalRead(BUTTON_PIN); // read new state
  
  if(lastButtonState2 == LOW && currentButtonState3 == HIGH) {
    Serial.print("The button is pressed: ");
  
    // toggle state of LED2
    if(ledState2 == HIGH) {
       ledState2 = LOW;  
       Serial.println("Turning LED2 off");
    }
    else {
      ledState2 = HIGH;
      Serial.println("Turning LED2 on");
    }
 
    // control LED arccoding to the toggled state
    digitalWrite(LED_PIN2, ledState3);  //turns the LED on or off based on the variable
  }
}
