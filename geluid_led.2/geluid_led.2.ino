//Develop by creative KHOPDI


//NOTE:-ADJUST/SET BY POTENTIOMETER OF SOUND SENSOR IF LESS NUMBER OF PATTERN OBSERVE

#include <FastLED.h>

int r=152;
int g=0;
int b=10;

#define LED_PIN     5            //CONNECT DATA PIN OF PIXEL WITH 5 NUMBER PIN OF ARDUINO
#define NUM_LEDS    60           //CHANGE THE VALUE IF YOU WANT TO USE DIFFRENT NUMBER OF LED IN YOUR STRIP,HERE IN MY STRIP NUMBER OF LED IS 60 SO I SET IT 60.

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int s=0;

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  for (int i = NUM_LEDS/2; i >= 0; i--) 
  {
     leds[i] = CRGB ( r,g,b);
     leds[NUM_LEDS-i] = CRGB (r,g,b );
     delay(40);
    FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}
void loop()
{
  s=analogRead(A0);
  s=s*2;
  Serial.println(s);
 // delay(50);
  if((s>=2046)&&(s<=2046))
  {
    leds[(NUM_LEDS/2)-1]=CRGB (0xFFFF00);
    leds[NUM_LEDS/2]=CRGB (0xFFFF00);
  }
  else if((s>=60)&&(s<=60))
  {
    leds[(NUM_LEDS/2)-1]=CRGB (168, 0, 31);
    leds[NUM_LEDS/2]=CRGB (168, 0, 31);
  }
  else
  {
     leds[(NUM_LEDS/2)-1] = CRGB ( 168, 0, 31);
     leds[NUM_LEDS/2] = CRGB ( 168, 0, 31);
  }
    for (int i = 0; i <= ((NUM_LEDS/2)-2); i++) 
  {
     leds[i] = leds[i+1];
     leds[NUM_LEDS-1-i] = leds[(NUM_LEDS)-i-2];
     
  }
 FastLED.show();
 delay(70);

}
