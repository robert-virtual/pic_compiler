#include<16f628a.h>
#fuses INTRC,NOMCLR, NOWDT
#use delay(clock=4M)

void main(){

    set_tris_b(0x00);
    output_b(0x00);
   while(true){

        output_b(0b01000001);//rojo y verde
        delay_ms(9000);
        
        output_b(0b00100001);// amarillo
        delay_ms(3000);
        
        output_b(0b00010100);// 
        delay_ms(9000);
        
        output_b(0b00010010);//amarillo 
        delay_ms(3000);

   }
   
   
}

