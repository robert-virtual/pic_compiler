#include <16f628a.h>
#fuses INTRC,NOMCLR,NOWDT
#use delay(clock=4M)

#byte port_b=0x06
#byte tris_b=0x86
byte miDisplay[10] = {0b00000110};
void main(){
 	tris_b = 0b00000000;
  	port_b = 0b11111111;//
  	int nums[] = {0b00000110,0b00000000};
	while(true){
		for(int i = 0; i < 2, i++){
			port_b = nums[i];
			delay_ms(500);
		}

	}
}