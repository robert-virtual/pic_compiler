#include <16f886.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)

#byte trisa=0x85
#byte portb=0x05
#byte porta=0x06

#define LCD_DATA_PORT getenv("SFR:PORTC")
#include <lcd.c>


void main(){
    lcd_init();
    int ghost[8]={
        0B00001110,
        0B00011111,
        0B00010101,
        0B00010101,
        0B00011111,
        0B00011111,
        0B00010101,
        0B00010101
    };
    int personPaused[8]={
        0B00001110,
        0B00001110,
        0B00000100,
        0B00011111,
        0B00000100,
        0B00000100,
        0B00001010,
        0B00010001
    };

    int personRunning[] = {
        0B00001110,
        0B00001110,
        0B00000100,
        0B00011111,
        0B00000100,
        0B00000100,
        0B00001010,
        0B00001010
    };


    lcd_set_cgram_char(0,ghost);
    lcd_gotoxy(1,1);
    lcd_putc(0);

    lcd_set_cgram_char(1,personPaused);
    lcd_gotoxy(20,1); // posision x = columna, y = fila
    lcd_putc(1);
    
    lcd_set_cgram_char(2,personRunning);
    bit_set(trisa,0); // 0 = entrada = pin ra0 = entrada
    int cols = 20;
    while(true){
        if(bit_test(porta,0) == 1){
            for(int i = 2; i <= cols;i++){
                lcd_putc("\f");        
                lcd_gotoxy(i,1);
                lcd_putc(0);        
                delay_ms(100);

                lcd_gotoxy(20,1);
                lcd_putc(1);        
                delay_ms(200);
                lcd_gotoxy(20,1);
                lcd_putc(2);        
                delay_ms(200);
            }
        }
    }
}
