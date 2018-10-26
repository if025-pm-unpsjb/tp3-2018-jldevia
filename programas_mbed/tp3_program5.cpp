#include "mbed.h"

Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
DigitalOut led4(LED4);

int main()
{
    char cmd = '0';
    char opc = '0';
    led1 = 0;
    led2 = 0;
    led3 = 0;
    led4 = 0;
        
    pc.baud(9600);
    
    while (1) {
        
        
        if (pc.readable()) {
            cmd = pc.getc();
        }
        
        if (cmd == '1' || cmd == '2' || cmd == '3' || cmd == '4') {
            opc = cmd;
        }    
        
        switch (opc) {
            case '1':
                led1 = !led1;
                led2 = led3 = led4 = 0;
                break;
            case '2':
                led2 = !led2;
                led1 = led3 = led4 = 0;
                break;
            case '3':
                led3 = !led3;
                led1 = led2 = led4 = 0;
                break;
            case '4':
                led4 = !led4;
                led1 = led2 = led3 = 0;
                break;

        }

        wait_ms(250);
        
    }

}