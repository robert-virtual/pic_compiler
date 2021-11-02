#include <16f628a.h>
#fuses INTRC,NOMCLR,NOWDT
#use delay(clock=4M)

#byte port_b=0x06
#byte tris_b=0x86

void main(){
   tris_b = 0b00000000;
  
   while(1){
      port_b = 0b11111111;
      delay_ms(100);
      port_b = 0b0000000;

      for(int i = 0; i < 8; i++){

         if(i%2 == 0){
          bit_set(port_b,i);
            delay_ms(100);
            bit_clear(port_b,i);   
         } 
      

         
      }
      for(int j = 8; j > 0; j--){
         if(j%2 != 0){
        bit_set(port_b,j);
         delay_ms(100);
         bit_clear(port_b,j);   
         }
         
      }
      port_b = 0b10101010;
    
   
      delay_ms(100);
      port_b = 0b01010101;
      delay_ms(100);

   }
}





