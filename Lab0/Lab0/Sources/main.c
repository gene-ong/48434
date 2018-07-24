/*!
** @file
** @version 1.0
** @brief
**         Main module.
**         This module implements a simple 12-hour clock.
**         It time-stamps button pushes and stores them in a FIFO used a packed representation.
*/         
/*!
**  @addtogroup main_module main module documentation
**  @{
*/         
/* MODULE main */


// CPU module - contains low level hardware initialization routines
#include "Cpu.h"

// Simple timer
#include "timer.h"

// Button functions
#include "buttons.h"

// LED functions
#include "LEDs.h"

//FIFO header file
#include "FIFO.h"

// The packed time representation

//   15             12   11                        6    5                       0
// |----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|----|
// |       hours       |          minutes            |          seconds            |

typedef uint16_t PackedTime_t;

// ***
// You will need to create a FIFO object with a size suitable to store 10 time-stamps using the packed time representation.
// ***

//global variables
static unit8_t Seconds = 0;
static unit8_t Minutes = 0;
static unit8_t Hours = 0;


static void OneSecondElapsed(void)
{
  LEDs_Toggle(LED_BLUE);
  // One second has elapsed - update the time here
  Seconds ++;

  if(Seconds>=60){
    Seconds = 0;
    Minutes ++;
  }

  if(Minutes>=60){
    Minutes = 0;
    Hours ++;
  }

  if(Hours>=15){
      Hours = 0;
  }
}

static void Button1Pressed(void)
{
  //local variable declarations
  uint16_t timeStamp;
  uint16_t readOutput;

  LEDs_Toggle(LED_ORANGE);

  //The button has been pressed - put a time-stamp into the FIFO
  //Convert the seconds, minutes and hours to a uint16_t
  //Hours + Minutes + Seconds -->
  timeStamp = (((uint16_t)Hours<<12) | ((uint16_t)Minutes<<6)|((uint16_t)Seconds))

  //write the timeStamp to the next available address in the buffer
  if (FIFO_Write(timeStamp))
    {
      //Error Message
    }

  //read the next available data in the buffer and store it at the address of readOutput
  if(FIFO_Read(&readOutput))
     {
       //Error Message
     }

}

static void TowerInit(void)
{
  PE_low_level_init();
  Timer_Init(OneSecondElapsed);
  Buttons_Init(Button1Pressed);
  LEDs_Init();
  __EI();
}

/*lint -save  -e970 Disable MISRA rule (6.3) checking. */
int main(void)
/*lint -restore Enable MISRA rule (6.3) checking. */
{
  TowerInit();
  /* Write your code here */

  BLAHBLAHBLAH

  for (;;)
  {
  }
}

/* END main */
/*!
** @}
*/
