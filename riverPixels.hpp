#pragma once


#include "wsPixels.hpp"

#define STEPS 255

using Pixel = struct xPixel;

class riverPixels: public wsPixels{

public:
    typedef struct _lineEq{
        int m;
        int b;
    }lineEq;

    typedef struct _colourPair{
        struct xPixel c1;
        struct xPixel c2;
    }colourPair;

    typedef struct _colorTransitions{
        lineEq red_transition;
        lineEq green_transition;
        lineEq blue_transition;

    }colourTransitions;

    riverPixels(uint8_t colour_cluster, uint8_t colour_count, colourPair* colours, unsigned int period);

    virtual int init();

    virtual int compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x);

    void start_transition();

    void create_transitions();

    void get_line(lineEq* eq, uint8_t y1, uint8_t y2);

private:
    unsigned int rp_same_colour_count;
    colourPair* rp_colours;
    uint8_t rp_colour_count;
    lineEq * transitionEqs;
    colourTransitions* rp_transitions;
    colourPair rp_current_colour;
    uint8_t rp_offset;
    uint8_t rp_transition;
    unsigned int rp_period_counts;
    unsigned int rp_transition_delta;


};