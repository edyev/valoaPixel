#include "wsPixels.hpp"

#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
#define LED_PIN     3


void wsPixels::hardware_init(){
    uint8_t n_leds;
    Serial.begin(9600);
    n_leds = this->get_total_pixels();

    delay( 3000 ); // power-up safety delay
    Serial.println(n_leds);
    wsl_leds = malloc(sizeof(CRGB) * n_leds);
    
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(
        wsl_leds, n_leds).setCorrection( TypicalLEDStrip );

    FastLED.setBrightness(  BRIGHTNESS );
     
    this->setPixelsLength(n_leds);
}


void wsPixels::hardware_set(unsigned int n, const struct xPixel* pixel){




    wsl_leds[n].setRGB(pixel->xp_rled,pixel->xp_gled,pixel->xp_bled);
}


    
void wsPixels::render(){
        FastLED.show();

}
