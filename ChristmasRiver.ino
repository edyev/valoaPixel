
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
     
    colours[0].c1 = {0, 0, 0xa};
    colours[0].c2 = {0x1, 0x1, 0xff};
    colours[1].c1 = {0, 0xa, 0xa};
    colours[1].c2 = {0, 0xff, 0xff};    
    colours[2].c1 = {0, 0xc, 0x2};
    colours[2].c2 = {0, 0xff, 0xa};
    colours[3].c1 = {30,5,0};
    colours[3].c2 = {255, 40, 0};
    colours[4].c1 = {0x10,0,0};
    colours[4].c2 = {0xff, 0, 0};
    colours[5].c1 = {0,0x10,0};
    colours[5].c2 = {0, 0xff, 0};
    colours[6].c1 = {0x5,0x5,0x5};
    colours[6].c2 = {0xf0, 0xf0, 0xf};
    colours[7].c1 = {0x10,0,0x10};
    colours[7].c2 = {0xff, 0, 0xff};
    colours[8].c1 = {0x50,0x50,0};
    colours[8].c2 = {0xff, 0xff,0};

  pixels = new riverPixels(2, NUMBER_PAIRS, colours, 500u );
  pixels->setPixelsLength(NUM_LEDS);
  pixels->hardware_init();

}

void loop() {
  pixels->run();
  potVal = analogRead(potPin);
  potVal = map(potVal, 0, 1023, 10, 100);
  delay(random(18, 180));
}
