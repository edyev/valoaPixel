
#include <FastLED.h>
#include <time.h>
#include "riverPixels.hpp"
#include "starPixels.hpp"


#define LED_PIN     3
#define NUM_LEDS    60
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB

xPixels* pixels;

void setup() {
  Serial.begin(9600);
  pixels = new starPixels(); //new riverPixels();
  pixels->setPixelsLength(NUM_LEDS);
  pixels->hardware_init();
}

void loop() {
  pixels->run();
  delay(18);
}
