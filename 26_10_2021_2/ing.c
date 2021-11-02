#include <16f28a.h>

#fuses INTRC,NOWDT,MCLR
#use delay(clock=4M);

#byte port_b=0x06
#byte port_a=0x05

#byte tris_a=0x85
#byte tris_b=0x86
#bit pulsador1=5.0

void main(){
    // tris_a = 0xff; // entrada
    bit_set(tris_a,0); //entrada
    tris_b = 0x00; // valores iniciales 
    // port_b = 0x00; // valores iniciales 
    port_b = 0b00000001; // valores iniciales 
    
    while(true){
        if(pulsador1 == 1){
            rotate_left(&port_b,1);

        } else {

            rotate_right(&port_b,1);

        }
        delay_ms(300);
    }    
}