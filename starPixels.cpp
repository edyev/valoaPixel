#include "starPixels.hpp"


starPixels::starPixels(){
    it = 0;
    colours[0] = {1, 0, 0};
    colours[1] = {0, 1, 0};
    colours[2] = {0, 0, 1};
    colours[3] = {1, 1, 0};

    fadeseq[0] = 0x5;
    fadeseq[1] = 0x25;
    fadeseq[2] = 0x2a;
    fadeseq[3] = 0x50;
    fadeseq[4] = 0x5a;
    fadeseq[5] = 0x90;
    fadeseq[6] = 0x9a;
    fadeseq[7] = 0xa0;
    fadeseq[8] = 0xaa;
    fadeseq[9] = 0xff;


}
int starPixels::init(){return 0;}

int starPixels::compute(
    struct xPixel* pixel, unsigned int pixel_n, unsigned int x)
{
    unsigned int hue;
    int direction;

    if ( 0 == x % 60 && 0 == pixel_n ){
        direction = random(0, 2) ? -1 : 1;
        Serial.println(x * direction);
        it = ( it+1 ) % 4;
    }

    if ( ( pixel_n + (int)x * direction) % 60  < 10 ){
        pixel->xp_rled = colours[it].xp_rled * fadeseq[( pixel_n + x * (int)direction)%60]; // colours[it].xp_rled / 5 * (pixel_n) ;
        pixel->xp_gled = colours[it].xp_gled * fadeseq[( pixel_n + x * (int)direction)%60]; //colours[it].xp_gled / 5 * (pixel_n);
        pixel->xp_bled = colours[it].xp_bled * fadeseq[( pixel_n + x * (int)direction)%60];
    }
    else{
        *pixel = {0};
    }

    return 0;
}

void starPixels::pre_sweep(){
    //it = ( it+1 ) % 4;

}