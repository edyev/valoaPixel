#include "xPixels.hpp"
#include <Arduino.h>

void xPixels::setPixelsLength(unsigned int n){
    xp_total_pixels = n;
}

// void xPixels::setComputeCallback(xComputeCallback cb){
//     xp_compute_callback = cb;
// }

void xPixels::run(){
    struct xPixel pixel;

    for (unsigned int n = 0; n < xp_total_pixels; ++n){
        //Serial.print(n);Serial.print(" , "); Serial.print( xp_x);
        this->compute(&pixel, n, xp_x ); 
        //Serial.print(" -> { ");Serial.print(pixel.xp_rled);Serial.print(", ");Serial.print(pixel.xp_gled);Serial.print(", ");Serial.print(pixel.xp_bled);Serial.println(" }");
        this->hardware_set(n, &pixel);
    }
    this->render();
    ++xp_x; 

}

unsigned int xPixels::get_total_pixels() const{
    return xp_total_pixels;
}
