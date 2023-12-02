#include "riverPixels.hpp"

#define SEQUENCES_COUNT 4

riverPixels::riverPixels(uint8_t colour_cluster, uint8_t colour_count, colourPair* colours, unsigned int period){
    rp_same_colour_count = colour_cluster;
    rp_colour_count = colour_count;
    rp_period_counts = period;
    rp_offset = 0;
    rp_colours = colours;
    rp_transition_delta = 10;
    rp_current_colour = rp_colours[rp_offset];

    this->create_transitions();
    // rp_period_counts = (lineEq*) malloc(sizeof(struct xPixel) * SEQUENCES_COUNT);

}

int riverPixels::init(){

}

void riverPixels::start_transition(){


}

void riverPixels::create_transitions(){
    rp_transitions = malloc( rp_colour_count / 2 * sizeof( lineEq ) );   
    
    for(int i = 0; i < rp_colour_count / 2; ++i ){

        this->get_line(&rp_transitions->red_transition, 
            rp_colours[i].c1.xp_rled, 
            rp_colours[i].c2.xp_rled);

        this->get_line(&rp_transitions->green_transition, 
            rp_colours[i].c1.xp_gled, 
            rp_colours[i].c2.xp_gled);

        this->get_line(&rp_transitions->blue_transition, 
            rp_colours[i].c1.xp_bled, 
            rp_colours[i].c2.xp_bled);

        rp_transitions++;
    }
    

}

void riverPixels::get_line(lineEq* eq, uint8_t y1, uint8_t y2){
    eq->m = ( y2 - y1 ) / rp_transition_delta ; 
    eq->b = y2 - eq->m * rp_transition_delta;
}


int riverPixels::compute(struct xPixel* pixel, unsigned int pixel_n, unsigned int x){
    unsigned int sel;
    bool transition_done = 0;
    int transition_delta = 0;

    sel = ( ( pixel_n - x) / rp_same_colour_count ) % 2;

    *pixel = sel ? rp_current_colour.c1 : rp_current_colour.c2;
    // Serial.println(rp_offset);
    // Serial.println(sel);

    if ( 0 == (x % rp_period_counts )  && x > 0 && pixel_n == 0){
        rp_current_colour = rp_colours[random(0, 9)];
        rp_transition = 1;
        transition_delta = 0;
        rp_offset++;
        rp_offset = rp_offset % rp_colour_count;
    }

    // if ( 1 == rp_transition ){

    //     rp_current_colour.xp_rled = 
    //         rp_transitions[rp_offset / 2].red_transition.m * transition_delta +
    //         rp_transitions[rp_offset / 2].red_transition.b ;

    //     rp_current_colour.xp_gled = 
    //         rp_transitions[rp_offset / 2].green_transition.m * transition_delta +
    //         rp_transitions[rp_offset / 2].green_transition.b ;

    //     rp_current_colour.xp_bled = 
    //         rp_transitions[rp_offset / 2].blue_transition.m * transition_delta +
    //         rp_transitions[rp_offset / 2].blue_transition.b ;
        
    //     if ( 0 == transition_delta - rp_transition_delta ){
    //         // rp_current_colour = rp_colours[sel]; 
    //         rp_transition = 0;

    //     }

    // }
    
    return 0;
}
