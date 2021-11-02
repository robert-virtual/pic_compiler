#include <16f28a.h>

#fuses INTRC,NOWDT,NMCL

void main(){

    set_tris_b(0x00);
    port_b = 0;
    
    while(true){
        if (!input(pin_a1)) {
            output_high(pin_b0);
        } else {
            output_low(pin_b0);
        }
    }    
}