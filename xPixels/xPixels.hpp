#pragma once

#include<stdint.h>

class xPixels{

public:
    struct xPixel{
        uint8_t xp_rled;
        uint8_t xp_gled;
        uint8_t xp_bled;        
    };
    typedef int* (xComputeCallback)(struct xPixel* pixel, unsigned int pixel_n, unsigned int x)  ;
    xPixels(): xp_x(0){};
    virtual int init() = 0;
    virtual void setPixelsLength(unsigned int n);
    virtual void setComputeCallback(xComputeCallback cb);
    virtual int compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x) = 0;
    virtual void hardware_set(const struct xPixel* pixel) = 0;
    void run();
    void step();


private:
    unsigned int xp_x;
    unsigned int xp_total_pixels;
    xComputeCallback xp_compute_callback;
};