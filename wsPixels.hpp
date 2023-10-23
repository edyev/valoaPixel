#pragma once

#include <FastLED.h>
#include "xPixels.hpp"

class wsPixels: public xPixels {

public:

    virtual void hardware_init()  final;
    virtual void hardware_set(unsigned int n, const struct xPixel* pixel);
    virtual void render() final;

private:
    CRGB* wsl_leds;

};