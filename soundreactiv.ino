#include <FastLED.h>

int r=252;
int g=0;
int b=0;

#define DATA_PIN 11
#define CLOCK_PIN 13
#define NUM_LEDS 20

CRGB leds[NUM_LEDS];
CRGB led[NUM_LEDS];
int s=A0;

void setup() {

  FastLED.addLeds<WS2801, DATA_PIN, CLOCK_PIN, RBG>(leds, NUM_LEDS);
  for (int i = 29; i >= 0; i--) 
  {
     leds[i] = CRGB ( r,g,b);
     leds[59-i] = CRGB (r,g,b );
     delay(40);
    FastLED.show();
  }
  Serial.begin(9600);
   pinMode(A0,INPUT);

}
void loop()
{
  s=analogRead(A0);
 
  if((s>=535)&&(s<=540))
  {
    leds[29]=CRGB (20, 135, 217);
    leds[30]=CRGB (20, 135, 217);
  }
  else if((s>=530)&&(s<=535))
   {
     leds[29]=CRGB (20, 217, 30);
    leds[30]=CRGB (20, 217, 30);
   }
  else
  {
     leds[29] = CRGB ( r,g,b);
     leds[30] = CRGB ( r,g,b);
  }
    for (int i = 0; i <= 28; i++) 
  {
     leds[i] = leds[i+1];
     leds[59-i] = leds[58-i];
     
  }
 FastLED.show();
 delay(30);

  
  
 
}
