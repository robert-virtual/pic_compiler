#include<16f628a.h>
#fuses INTRC,NOMCLR, NOWDT
#use delay(clock=4M)

#use standard_io(B,A)

#bit led1=6.0

void main(){

    // int pins[3] = {pin_b0,pin_b1,pin_b2};
   while(true){

    if(input(pin_a0)){
        output_high(pin_b0);
        output_low(pin_b2);

    }

    if(input(pin_a1)){
        output_high(pin_b1);
        output_low(pin_b2);

    }
    if(input(pin_a2)){
        output_low(pin_b0);
        output_low(pin_b1);
        output_high(pin_b2);

    }
    


        

   }
   
   
}