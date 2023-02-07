int intensity = 255;
int d = 5;
// the setup function runs once when you press reset or power the board
void setup() {
 // initialize digital pin 10 as an output.
 pinMode(10, OUTPUT);
 pinMode(11, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  while((intensity > 255) && (intensity <= 1)) //rood licht uit
 {
   analogWrite(10, intensity);    
   delay(d);  
   intensity = intensity + 200;    
 }
  
 while(intensity !=0) //rood licht aan
 {
   analogWrite(10, intensity);    
   delay(d);  
   intensity = intensity - 0.5200;
 } 




  while((intensity > 1) && (intensity <= 255)) //groen lict uit
  {
   analogWrite(11, intensity);    
   delay(d);  
   intensity = intensity - 100;
 }
 
 while(intensity != 255) //groen licht aan
 {
     analogWrite(11, intensity);    
   delay(d);  
   intensity = intensity + 1;    
 }


}
