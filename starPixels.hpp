#pragma once


#include "wsPixels.hpp"


class starPixels: public wsPixels{
private:
    struct xPixel colours[4];
    uint8_t fadeseq[10];
    unsigned int it;
    int direction;


public:
    starPixels();
    virtual int init();
    virtual int compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x);
    virtual void pre_sweep();
};