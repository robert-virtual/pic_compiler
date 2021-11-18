#include <16f886.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)



#define LCD_DATA_PORT getenv("SFR:PORTC")
#include <lcd.c>


void main(){
    lcd_init();
    int c[8]={
        0B00011000,
        0B00011011,
        0B00000111,
        0B00001100,
        0B00001100,
        0B00001100,
        0B00000111,
        0B00000011
    };

    int smile[8] = {
        0B00000000,
        0B00001010,
        0B00000000,
        0B00010001,
        0B00001110,
        0B00000000,
        0B00000000,
        0B00000000
    };
   

    

        lcd_set_cgram_char(0,c);
        lcd_set_cgram_char(1,smile);
    
    while(true){
        lcd_putc("\f"); // limpiar       

        lcd_gotoxy(1,1);
        printf(lcd_putc,"Danli");
        delay_ms(1500); // pausa
        

        lcd_putc("\f"); // limpiar       

        lcd_gotoxy(1,1);
        printf(lcd_putc,"T.Actual:22");

        lcd_gotoxy(13,1);
        lcd_putc(0);
    
        lcd_gotoxy(15,1);
        lcd_putc(1);
        delay_ms(2000); // pausa
               
        
    }
}
