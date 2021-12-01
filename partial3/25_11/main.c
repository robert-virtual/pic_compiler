#include <16f886.h>

#device adc=10
#fuses NOWDT,MCLR,HS
#use delay(clock=20M)
#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>
long valor_adc;//potenciometro 
float voltaje;//potenciometro 
// #use standard_io(a,b)

void main(){
    // configurar pin a anologivo
    setup_adc_ports(sAN0); // like set_tris pero para valores analogioca
    setup_adc(ADC_CLOCK_INTERNAL);
   
    lcd_init();
    while(true){
        // canal(pin) donde recibira el valor analogivo 
        set_adc_channel(0);
        delay_us(2); // microsegundos
        valor_adc = read_adc();
        voltaje = (valor_adc*5.0)/1023;

        lcd_putc("\f");

        lcd_gotoxy(1,1);
        printf(lcd_putc,"ADC: %lu",valor_adc);
        delay_ms(300); // microsegundos
        // lu = decimal sin signo
        lcd_gotoxy(1,2);
        printf(lcd_putc,"Voltaje: %.2f",voltaje);
        delay_ms(300); // microsegundos
    }
}

