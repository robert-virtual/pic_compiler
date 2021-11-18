#include <16f886.h>

#fuses INTRC,NOWDT,NOMCLR

#use delay(clock=4M)
#use standard_io(a,b)


#define LCD_DATA_PORT getenv("SFR:PORTC")
#include <lcd.c>



void llenarTanque(){
    output_toggle(pin_b0);
}
void pausarLlenado(){
    output_toggle(pin_b1);
}
void medirTanque(){
    output_toggle(pin_b2);
}

void main(){
    lcd_init();
    int item = 0;
    while(true){
        if(input(pin_a0) == 1){
           delay_ms(400);
            item++;
           if(item == 3){
               item = 0; 
           }
        }
        switch(item){
            case 0:
                lcd_gotoxy(1,1);
                printf(lcd_putc,"1.Llenar tanque");
            break;
            case 1:
                lcd_gotoxy(1,1);
                printf(lcd_putc,"2.Pausar llenado");
            break;
            case 2:
                lcd_gotoxy(1,1);
                printf(lcd_putc,"3.Medir llenado");
            break;
        }
        // elegir opcion
        if(input(pin_a1) == 1){
            delay_ms(400);

            switch(item){
                case 0:
                    llenarTanque();
                break;
                case 1:
                    pausarLlenado();
                break;
                case 2:
                    medirTanque();
                break;
            }
            
        }
    }
}
