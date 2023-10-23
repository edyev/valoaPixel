#pragma once


#include "wsPixels.hpp"


class linearPixels: public wsPixels{

public:
    linearPixels(){}
    virtual int init();
    virtual int compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x);
};