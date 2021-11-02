#include <16f28a.h>

#fuses INTRC,NOWDT

#byte port_b=0x06
#byte tris_a=0x85
#byte tris_b=0x86

#bit EN1=5.0
#bit EN2=5.1
#bit Led1=6.0


void main(){

    tris_a=0xff;

    while(true){
        
    }    
}