/*============================================================================
 * Autor: Devia José Luis
 * Asignatura : Sistemas Embebidos y de Tiempo Real 
 * Fecha: 22/10/2018.
 *===========================================================================*/

// DEPENDENCIAS

#include "app.h"         // <= Su propia cabecera (opcional)
#include "sapi.h"        // <= Biblioteca sAPI

// FUNCION PRINCIPAL, PUNTO DE ENTRADA AL PROGRAMA LUEGO DE ENCENDIDO O RESET.
int main( void )
{
   // ---------- CONFIGURACIONES ------------------------------

   // Inicializar y configurar la plataforma
   boardConfig();

   uartConfig(UART_USB,9600);
   
   int8_t opc; 
   bool_t ok;
   bool_t ledValue; 
   
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
     ok = uartReadByte(UART_USB, &opc);
              
     switch (opc) {
            case '1':
                ledValue = gpioRead(LED1);
                gpioWrite(LED1, !ledValue);
                gpioWrite(LED2, OFF);
                gpioWrite(LED3, OFF);
                gpioWrite(LEDB, OFF);
                break;
            case '2':
                ledValue = gpioRead(LED2);
                gpioWrite(LED1, OFF);
                gpioWrite(LED2, !ledValue);
                gpioWrite(LED3, OFF);
                gpioWrite(LEDB, OFF);
                break;
            case '3':
                ledValue = gpioRead(LED3);
                gpioWrite(LED1, OFF);
                gpioWrite(LED2, OFF);
                gpioWrite(LED3, !ledValue);
                gpioWrite(LEDB, OFF);
                break;
            case '4':
                ledValue = gpioRead(LEDB);
                gpioWrite(LED1, OFF);
                gpioWrite(LED2, OFF);
                gpioWrite(LED3, OFF);
                gpioWrite(LEDB, !ledValue);
                break;
     }
         
      /* Retardo bloqueante durante 250 ms */
      delay( 250 );
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
