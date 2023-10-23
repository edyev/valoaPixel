#include "xPixels.hpp"


void xPixels::setPixelsLength(unsigned int n){
    xp_total_pixels = n;
}

// void xPixels::setComputeCallback(xComputeCallback cb){
//     xp_compute_callback = cb;
// }

void xPixels::run(){
    struct xPixel pixel;

    for (int n = 0; n < xp_total_pixels; ++n){
        this->compute(&pixel, n, xp_x );
        ++xp_x; 
    }

}