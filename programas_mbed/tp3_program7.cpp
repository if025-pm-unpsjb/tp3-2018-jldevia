#include "mbed.h"

DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

Serial pc(USBTX, USBRX);

int main() {
    int frecuencia = 0;
    int numero = 0;
    
    pc.baud(9600);
        
    while(1) {
        if ( pc.readable() ) {
            pc.scanf("%d", &frecuencia);
            pc.printf("Entrada: %d", &frecuencia);    
        }
        
        if (frecuencia == 0 || frecuencia == NULL){
            frecuencia = 500;
        }
        
             
        
        led1 = numero & 0x0001;
        led2 = (numero >> 1)  & 0x0001;
        led3 = (numero >> 2) & 0x0001;
        led4 = (numero >> 3) & 0x0001;
        
        wait_ms(frecuencia);
        
        numero = numero + 1;
        
        if ( numero > 15) {
            numero = 0;
        }
        
    }
}
