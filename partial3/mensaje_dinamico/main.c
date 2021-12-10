#include <16f886.h>

#fuses NOWDT,NOMCLR,INTRC

#use delay(clock=4M)

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

char mensaje[25] = "Hola mundo";
char mensaje2[25] = "roberto Castillo";




void main(){

    lcd_init();
    while(true){

        int j = 0;

        lcd_putc("\f");
        for(int i = 20; i > 0; i-- ){
            lcd_putc("\f");
            lcd_gotoxy(i,1); // posicion dle mensaje
            printf(lcd_putc,"%s",mensaje); // imprimir mensaje
            delay_ms(300);
            j++;
        }

        lcd_gotoxy(1,2); // posicion dle mensaje
        printf(lcd_putc,"%s",mensaje2); // imprimir mensaje



    }


}
