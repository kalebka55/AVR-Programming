/* 
   Demo of the simple on/off button code
*/

#include <inttypes.h>
#include <avr/io.h>
#define F_CPU  8000000UL
#include <util/delay.h>

#define INPUT_PIN     PD2
#define INPUT_PORT    PORTD
#define INPUT_DDR     DDRD
#define INPUT_INPUT   PIND     

#define LED_PORT PORTB
#define LED_DDR  DDRB
#define LED      PB7 

void main(void){
    
  INPUT_PORT = (1 << INPUT_PIN);/* initialize pullup resistor on our input pin */
  LED_DDR = (1 << LED);	      /* set up LED for output */


  while(1){                     /* mainloop */    

    /* light up when button pressed */
    if ((INPUT_INPUT & (1 << INPUT_PIN)) == 0){       /* pin is negative logic */
      LED_PORT = (1 << LED);
    }  
    else
      LED_PORT &= ~(1 << LED);
  } /* end mainloop */

}
