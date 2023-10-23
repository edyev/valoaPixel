
#include <FastLED.h>
#include <time.h>
#include "riverPixels.hpp"
#include "xPixels.hpp"

#define LED_PIN     3
#define NUM_LEDS    60
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define NUMBER_PAIRS  (uint8_t)5
xPixels* pixels;

riverPixels::colourPair* colours;
void setup() {
  Serial.begin(9600);
    colours = (riverPixels::colourPair*) malloc(sizeof(riverPixels::colourPair) * NUMBER_PAIRS );
     
    colours[0].c1 = {0, 0, 0xff};
    colours[0].c2 = {0xa0, 0xa0, 0};
    colours[1].c1 = {0, 0xa0, 0};
    colours[1].c2 = {0xa, 0, 0xf0};    
    colours[2].c1 = {0, 0xff, 0xff};
    colours[2].c2 = {0xff, 0, 0xff};
    colours[3].c1 = {0xff,0,0};
    colours[3].c2 = {0xff, 0xff, 0xff};
    colours[4].c1 = {0x10,0x10,0x10};
    colours[4].c2 = {0xff, 0xff, 0xff};

  pixels = new riverPixels(5, NUMBER_PAIRS, colours, 50u );
  pixels->setPixelsLength(NUM_LEDS);
  pixels->hardware_init();

}

void loop() {
  pixels->run();
  delay(80);
}
