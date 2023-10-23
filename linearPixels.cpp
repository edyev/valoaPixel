#include "linearPixels.hpp"


int linearPixels::init(){
    return 0;
}

int linearPixels::compute(
    struct xPixel* pixel, unsigned int pixel_n, unsigned int x)
{
    pixel->xp_rled = 0x10;
    pixel->xp_gled = 0;
    pixel->xp_bled = 0xff;
    
    return 0;
}

