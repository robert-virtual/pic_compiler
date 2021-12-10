#include <16f886.h>

#device adc=10
#fuses NOWDT,NOMCLR,HS

#use delay(clock=20M)

#define LCD_DATA_PORT getenv("SFR:PORTB")
#include <lcd.c>

float voltaje; 
#use standard_io(a,b)
#bit lampara=7.7//pin 7 puerto c(rc7)
#include <string.h>


int automatico = 1;
char modo[] = "Automatico"; 
char estado[10]; 
int i = 0;
void main(){
    // configurar pin a anologivo
    setup_adc_ports(sAN0); // like set_tris pero para valores analogioca
    setup_adc(ADC_CLOCK_INTERNAL);// como convertir de analogico a digital
   
    lcd_init();
    while(true){
        // canal(pin) donde recibira el valor analogivo 
        set_adc_channel(0);
        delay_us(2); // microsegundos
        float valor_adc = read_adc();
         voltaje = (valor_adc*5.0)/1023;
        // 1023 = resolucion
        if(lampara == 1){
            delay_ms(500);
            estado = "on";

        }else{
            delay_ms(500);
            estado = "off";

        }    



        char mostrar[20];
        char mensaje[50] = "Lampara: ";
        
        strcat(mensaje, estado);
        char src3[] = " modo: ";
        strcat(mensaje, src3);
        strcat(mensaje, modo);
         if(automatico == 1){
            delay_ms(300); // microsegundos
            if(voltaje > 2.47){
                delay_ms(300);
                output_high(pin_c7);

            } else {
                delay_ms(300);
                output_low(pin_c7);
            }
        }

        
        lcd_putc("\f");
        lcd_gotoxy(1,1);
        int idx = i;
        for(int j = 0; j < 20 ;j++){
            mostrar[j] = mensaje[idx];
            idx++;
        }
        printf(lcd_putc,mostrar);
        delay_ms(300); // microsegundos
        
        lcd_gotoxy(1,2);
        printf(lcd_putc,"Detectado: %.2f luz",voltaje);
        delay_ms(300); // microsegundos

       
        
        if(input(pin_c4) == 1) {
            delay_ms(300); // microsegundos
            automatico = 1;
            modo = "Automatico"; 
        }
        
       

        if(input(pin_c5) == 1){
            delay_ms(500);
            output_toggle(pin_c7);
            automatico = 0;
            modo = "Manual";
            

        } 
        
        if(i == 20) 
            i = 0;
        i++;
        
    }
}

