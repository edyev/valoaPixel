
#include <FastLED.h>
#include <time.h>
#include "riverPixels.hpp"
#include "xPixels.hpp"

#define LED_PIN     3
#define NUM_LEDS    60
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUMBER_PAIRS  (uint8_t)9

xPixels* pixels;
riverPixels::colourPair* colours;
const int potPin = A0;
unsigned int potVal = 0;

void setup() {
  Serial.begin(9600);
    colours = (riverPixels::colourPair*) malloc(sizeof(riverPixels::colourPair) * NUMBER_PAIRS );
     
    colours[0].c1 = {0, 0, 0xff};
    colours[0].c2 = {0xff, 0xff, 0};
    colours[1].c1 = {0xff, 0, 0xff};
    colours[1].c2 = {0, 0xff, 0xff};    
    colours[2].c1 = {0xff, 0xff, 0xff};
    colours[2].c2 = {0xff, 0, 0};
    colours[3].c1 = {0x2e,0xcc,0x71}; 
    colours[3].c2 = {0x89, 0x5c, 0xde};
    colours[4].c1 = {0xf9,0xe7,0x9f}; 
    colours[4].c2 = {0xf5, 0xcb, 0xa7}; 
    colours[5].c1 = {0xaf,0x7a,0xc4};
    colours[5].c2 = {0x29, 0x80, 0xb9}; 
    colours[6].c1 = {0x2e,0xcc,0x71}; 
    colours[6].c2 = {0xf4, 0xd0, 0x3f}; 
    colours[7].c1 = {0x5d,0x6d,0x7e}; 
    colours[7].c2 = {0xd1, 0xf2, 0xeb};  
    colours[8].c1 = {0x99,0x33,0xff};
    colours[8].c2 = {0xff, 0xff,0xff};

  pixels = new riverPixels(8, NUMBER_PAIRS, colours, 500u );
  pixels->setPixelsLength(NUM_LEDS);
  pixels->hardware_init();

}

void loop() {
  pixels->run();
  delay(100);
}
