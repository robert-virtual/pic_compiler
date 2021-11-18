#include<16f628a.h>
#fuses INTRC,NOMCLR, NOWDT
#use delay(clock=4M)

#use standard_io(B,A)

#bit ledventana1=6.0
#bit ledpuerta=6.2
#bit ledventana2=6.4
#bit ledestadoalarma=6.7

int alarma = 0;

void main(){

   for(;;){


    if( alarma == 1 && ledestadoalarma == 1){
        delay_ms(500);
        output_high(pin_b5);
        delay_ms(500);
        output_low(pin_b5);
        
    } 


    if(input(pin_a0) && ledestadoalarma == 0){
        delay_ms(300);
        output_high(pin_b7);
        alarma = 0;
    }
    if(input(pin_a0) && ledestadoalarma == 1){
        delay_ms(300);
        output_low(pin_b7);
        //desacivar alarma
        alarma = 0;
    }



    if(input(pin_a3) && ledventana2 == 0){
        delay_ms(300);
        alarma = 1;
    }
  


    if(input(pin_a1) && ledventana1 == 0){
        delay_ms(300);
        alarma = 1;
    }
    

    if(input(pin_a2) && ledpuerta == 0){
        delay_ms(300);
        alarma = 1;
    }
   

    
   }
}