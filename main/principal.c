/*
 * principal.c
 *
 *  Created on: 15 dic. 2020
 *      Author: William
 */


#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#include "UARTconfig.c"
#include "LEDControl.c"


#define Pila 1024
#define ColaSize 1
#define MsnSize 1


xQueueHandle ColaUART;



void app_main(void){

	iniciarUART();
	configGPIO();
	ColaUART = xQueueCreate( ColaSize, MsnSize );

	xTaskCreatePinnedToCore( &LEDControl, "Led_Control", Pila, NULL, 5, NULL, 0 );

}


