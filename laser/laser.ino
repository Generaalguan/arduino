

#define DETECT 2 // pin 2 for  sensor
#define ACTION 8 // pin connected aan led strip(sterren)
#define led 9 // pin connected aan lamp(zon)

void setup() {
  Serial.begin(9600);

  pinMode(DETECT, INPUT);//define detect input pin
  pinMode(ACTION, OUTPUT);//define ACTION output pin
  pinMode(led, OUTPUT);//define ACTION output led 

} void loop() {   int detected = digitalRead(DETECT);// read Laser sensor
  if( detected == HIGH)
  {
    digitalWrite(ACTION,HIGH);// set the zon ON
    Serial.println("Detected!");   }
  else{
  
    digitalWrite(ACTION,LOW); // Set the zon OFF
    Serial.println("No laser");   }     
   if( detected == HIGH)
  {
    digitalWrite(led,LOW);// set the sterren ON
    Serial.println("no led!"); }
  else{  
    digitalWrite(led,HIGH); // Set the sterren OFF
    Serial.println("led on");
  }
  delay(200);
}
