#include <16f628a.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)

#use standard_io(B)

#byte portb=0x06
#bit btn1=5.0
#bit btn2=5.1
#bit led=6.0


void main(){
    set_tris_a(0xff);
    set_tris_b(0x00);
    portb=0x00;
    while(true){
       if(btn1 == 1 && led==0){
           delay_ms(100);
           led = 1;
           
       }
       if(btn2 == 1 && led == 0){
           delay_ms(100);
           led = 1;
       }

       if(btn2 == 1 && led == 1){
           delay_ms(100);
           led = 0;
       }

       if(btn1 == 1 && led == 1){
           delay_ms(100);
           led = 0;
       }


    }
}
void antirebote(){
    while(btn1=01 || btn2=01){}
    delay_ms(100);
}

/*
while(true){
       if((btn1 == 1 && i == 0 ) || (btn2 == 1 && i == 0 )){
           i = 1;
       }
       if((btn1 == 0 && i == 1) || (btn2 == 0 && i == 1 )){
           output_toggle(PIN_B0);
           i = 0;
       }
    }

*/