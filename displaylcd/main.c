#include<16f6886.h>

#define LCD_DATA_PORT getenv("SFR:PORTB");
#include<lcd.c>

#fuses INTRC,NOMCLR, NOWDT
#use delay(clock=4M)


void main(){

    lcd_init();
   for(;;){

    lcd_putc("/f");
    lcd_gotoxy(1,1);
    printf(lcd_putc,"Bienvenido!");
    delay_ms(1000);
    
    lcd_putc("/f");
    lcd_gotoxy(4,2);
    printf(lcd_putc,"Bienvenido!");
    delay_ms(1000);

    
   }
}