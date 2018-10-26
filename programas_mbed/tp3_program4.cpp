#include "mbed.h"

Serial pc(USBTX, USBRX);

int main()
{
    while (1) {
        if ( pc.readable() ) {
            char c = pc.getc();

            if (c == 'h') {
                pc.printf("Hola Mundo con MBed!!");
            }
        }
        
        wait(1);
    }

}
