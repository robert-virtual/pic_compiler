#include<16f628a.h>
#fuses INTRC,NOMCLR, NOWDT
#use delay(clock=4M)

#use standard_io(B,A)

#bit led_win1=6.0
#bit led_door=6.2
#bit led_win2=6.4
#bit led_alarma=6.5
#bit led_estado_alarma=6.7

int alarma = 0;

void main(){

   while(true){


    // verificar alarma
    if( alarma == 1 && led_estado_alarma == 1){
        delay_ms(500);
        output_high(pin_b5);
        delay_ms(500);
        output_low(pin_b5);
        
    }
    // verificar alarma


    // activar alarma
    if(input(pin_a0) && led_estado_alarma == 0){
        delay_ms(300);
        output_high(pin_b7);
    }
    if(input(pin_a0) && led_estado_alarma == 1){
        delay_ms(300);
        output_low(pin_b7);
        alarma = 0;
    }
    // activar alarma



    // activar ventana 2
    if(input(pin_a3) && led_win2 == 0){
        delay_ms(300);
        output_high(pin_b4);
        alarma = 1;
    }
    if(input(pin_a3) && led_win2 == 1){
        delay_ms(300);
        output_low(pin_b4);
    }
    // activar ventana 2


    // activar ventana 1
    if(input(pin_a1) && led_win1 == 0){
        delay_ms(300);
        output_high(pin_b0);
        alarma = 1;
    }
    if(input(pin_a1) && led_win1 == 1){
        delay_ms(300);
        output_low(pin_b0);
    }
    // activar ventana 1

    // activar puerta
    if(input(pin_a2) && led_door == 0){
        delay_ms(300);
        output_high(pin_b2);
        alarma = 1;
    }
    if(input(pin_a2) && led_door == 1){
        delay_ms(300);
        output_low(pin_b2);
    }
    // activar puerta

    
   }
}