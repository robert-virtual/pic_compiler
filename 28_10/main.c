#include <16f628a.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)

#bit IN=5.0
#bit out=5.1
#bit LEDVerde=6.0
#bit LEDYellow=6.1
#bit LEDROJO=6.2


#byte port_a=0x05
#byte port_b=0x06

#byte tris_a=0x85
#byte tris_b=0x86

int i = 0;
void verificar(){
    if(i >= 9){
        LEDROJO = 1;
        LEDYellow = 0;
        LEDVerde = 0;
        //output_b(0b0000000)
    } else if(i >= 6 && i <= 8){
        LEDYellow = 1;
        LEDROJO = 0;
        LEDVerde = 0;
    } else {
        LEDVerde = 1;
        LEDYellow = 0;
        LEDROJO = 0;
    }
}
void main(){
    tris_a = 0b11111111;
    tris_b = 0b00000000;
    port_b = 0b00000001;
    while(true){
        if(IN == 1 && i <= 9){
            i++;
            delay_ms(200);
            verificar();
        }
        if(out == 1 && i > 0){
            i--;
            delay_ms(200);
            verificar();
        }
    }
}