#include <16f886.h>

#fuses INTRC,NOWDT,MCLR
#use delay(clock=4M)
#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

// #use standard_io(a,b)
#byte port_a=0x05
#byte port_c=0x07

int x = 0;
void main(){
   set_tris_a(0xff);
   set_tris_c(0x00);
   port_c = 0x00;
   lcd_init();
    while(true){
        if( x == 0 ){
            printf(lcd_putc,"RC");
            
            lcd_gotoxy(2,2);
            printf(lcd_putc,"Micro PICs");
            delay_ms(300);
            
            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Control de giro");

            lcd_gotoxy(2,2);
            printf(lcd_putc,"MOtor DC");
            
            x = 1;
        }
        if(bit_test(port_a,0) == 1 && x == 1){

            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Giro Directo");
            
            lcd_gotoxy(1,2);
            printf(lcd_putc,"Motor 1 ON");
            bit_set(port_c,0);
            bit_set(port_c,1);
            x = 2;
        }

        if(bit_test(port_a,1) && x == 1){

            lcd_putc("\f");
            lcd_gotoxy(1,1);
            printf(lcd_putc,"Giro Inverso");

            lcd_gotoxy(1,2);
            printf(lcd_putc,"Motor 1 en ON");
            bit_set(port_c,0);
            bit_set(port_c,2);
            x = 2;

        }
       
    }
}

