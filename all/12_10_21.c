#include<16f628a.h>
#fuses INTRC,NOMCLR, NOWDT
//oscilador interno no master clear,no watch dot timer(bucles infinitos)
#use delay(clock=4M)

#use standard_io(B)//configura puertos etc

void main(){

    int i = 0;
    while( i < 5 ){
        output_high(pin_b0);
        delay_ms(500);
        output_low(pin_b0);
        delay_ms(500); 
        i++;
    }
   
   
}
