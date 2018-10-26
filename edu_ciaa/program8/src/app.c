/*============================================================================
 * Autor: Devia José Luis
 * Asignatura: Sistemas Embebidos y de Tiempo Real 
 * Fecha: 24/10/2018.
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

   // Crear varias variables del tipo booleano
   bool_t buttonValue = OFF;
   bool_t ledBValue    = ON;
   bool_t led1Value    = ON;
   bool_t led2Value    = ON;
   bool_t led3Value    = ON; 
    
   // Botones
   gpioConfig( TEC1, GPIO_ENABLE );
   gpioConfig( TEC2, GPIO_ENABLE );
   gpioConfig( TEC3, GPIO_ENABLE );
   gpioConfig( TEC4, GPIO_ENABLE );
   
   //LED
   gpioConfig( LEDB, GPIO_OUTPUT );
   gpioConfig( LED1, GPIO_OUTPUT );
   gpioConfig( LED2, GPIO_OUTPUT );
   gpioConfig( LED3, GPIO_OUTPUT );
             
   // ---------- REPETIR POR SIEMPRE --------------------------
   while( TRUE ) {
       
      // ON-OFF LEDB
      buttonValue = gpioRead( TEC1 );
            
      if ( buttonValue != ledBValue ) {
         ledBValue = gpioToggle( LEDB );
      }
      
      // ON-OFF LED1
      buttonValue = gpioRead( TEC2 );
            
      if ( buttonValue != led1Value ) {
         led1Value = gpioToggle( LED1 );
      }
     
      // ON-OFF LED2
      buttonValue = gpioRead( TEC3 );
            
      if ( buttonValue != led2Value ) {
         led2Value = gpioToggle( LED2 );
      }
      
      // ON-OFF LED2
      buttonValue = gpioRead( TEC4 );
            
      if ( buttonValue != led3Value ) {
         led3Value = gpioToggle( LED3 );
      }
     
      /* Retardo bloqueante durante 300ms */
      delay( 300 ); 
           
                  
   }

   // NO DEBE LLEGAR NUNCA AQUI, debido a que a este programa se ejecuta
   // directamenteno sobre un microcontroladore y no es llamado por ningun
   // Sistema Operativo, como en el caso de un programa para PC.
   return 0;
}
