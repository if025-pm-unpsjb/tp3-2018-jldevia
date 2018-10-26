/*============================================================================
 * Autor:
 * Licencia:
 * Fecha:
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
    
   bool_t buttonValue = ON; 

   rgbConfig (RGB_1, LEDR, LEDG, LEDB);


   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {

      buttonValue = gpioRead(TEC1);
      
      if (buttonValue) {
        rgbToggleLed(RGB_1);
      } 
       
      /* Retardo bloqueante durante 100ms */
      delay( 500 );
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
