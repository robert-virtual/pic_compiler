#include <16f886.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)
#use standard_io(a,b)








void main(){
   
    while(true){
        if(input(pin_a2) == 1 ){
           delay_ms(400);
          output_toggle(pin_b2);
        } 
       

        
    }
}
