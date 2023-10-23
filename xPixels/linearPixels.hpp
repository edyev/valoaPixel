#pragma once


#include "xPixels.hpp"


class linearPixels: public xPixels{

public:
    linearPixels(){};
    virtual int init();
    virtual void setPixelsLength(unsigned int n);
    virtual int compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x);
    virtual void hardware_set(const struct xPixel* pixel);
};