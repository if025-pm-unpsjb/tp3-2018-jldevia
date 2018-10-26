#include "mbed.h"

PwmOut led1(LED1);
DigitalOut led4(LED4);

// main() runs in its own thread in the OS
int main() {
    led1 = 0;
    float incremento = 0.1; // 0.1 ó -0.1
    while (true) {
        led1 = led1 + incremento;
        wait_ms(500);
        
        if (led1 == 1){
            incremento = -0.1;
            led4 = 1;        
        }
        
        if (led1 == 0) {
            incremento = 0.1;
            led4 = 0;
        }
    }
}

