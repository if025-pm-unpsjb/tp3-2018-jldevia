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
   
    pwmConfig( 0, PWM_ENABLE );
    pwmConfig(PWM7, PWM_ENABLE_OUTPUT); 

   uint8_t incremento = 0; // 10 ó -10
   uint8_t intensidad = 0; 

   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
      intensidad = intensidad + incremento;
      pwmWrite(PWM7, intensidad); 

      /* Retardo bloqueante durante 500ms */
      delay( 500 );
       
      if ( intensidad == 255 ) {
          incremento = -15;
          gpioWrite(LEDB,ON);
      }
     
     if ( intensidad == 0 ) {
         incremento = 15;
         gpioWrite(LEDB,OFF);
     } 
      
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
