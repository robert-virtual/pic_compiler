#include <16f628a.h>

#fuses INTRC,NOWDT,MCLR
#use delay(clock=4M)

#byte port_b=0x06
#byte port_a=0x05

#byte tris_a=0x85
#byte tris_b=0x86



void main(){
    // tris_a = 0xff; // entrada
    bit_set(tris_a,0); //entrada
    tris_b = 0x00; // valores iniciales 
    port_b = 0x00; // valores iniciales 
    
    while(true){
        if(bit_test(port_a,0) == 1){
            for(int i = 0; i < 8; i++){
                bit_set(port_b,i);
                delay_ms(300);
            }

        } else {
            for(int i = 8; i < 0; i--){
                bit_set(port_b,i);
                delay_ms(300);
            }

        }
    }    
}
