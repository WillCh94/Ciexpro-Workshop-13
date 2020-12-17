/*
 * LEDControl.c
 *
 *  Created on: 15 dic. 2020
 *      Author: William
 */

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include "driver/gpio.h"
#include <string.h>

#define LED1 19
#define LED2 21
#define LED3 22
#define LED4 23
#define LED5 23
#define LED6 25
#define LED7 26

extern xQueueHandle ColaUART;

static const enum LEDnum {

	ledoff = 0,
	led1,
	led2,
	led3,
	led4,
	led5,
	led6,
	led7,
	LedsChange,

};



void configGPIO( void ){

	gpio_set_direction( LED1, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED2, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED3, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED4, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED5, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED6, GPIO_MODE_INPUT_OUTPUT );
	gpio_set_direction( LED7, GPIO_MODE_INPUT_OUTPUT );

}


static void LedControl( char LedSignal){

	switch( LedSignal ){

	case ( ledoff +'0' ):{

		char mensj[] = "TODOS LOS LEDS HAN SIDO APAGADOS\n\r";

		gpio_set_level( LED1, 0 );
		gpio_set_level( LED2, 0 );
		gpio_set_level( LED3, 0 );
		gpio_set_level( LED4, 0 );
		gpio_set_level( LED5, 0 );
		gpio_set_level( LED6, 0 );
		gpio_set_level( LED7, 0 );

		uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );

	}break;

		case ( led1 +'0' ):{

			char mensjUp[] = "LED 1 ENCENDIDO\n\r", mensjDown[] = "LED 1 APAGADO\n\r";

			gpio_set_level( LED1, !gpio_get_level( LED1 ) );

			if ( gpio_get_level( LED1 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );

		}break;

		case ( led2 +'0' ):{

			char mensjUp[] = "LED 2 ENCENDIDO\n\r", mensjDown[] = "LED 2 APAGADO\n\r";

			gpio_set_level( LED2, !gpio_get_level( LED2 ) );

			if ( gpio_get_level( LED2 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );

		}break;

		case ( led3 +'0' ):{

			char mensjUp[] = "LED 3 ENCENDIDO\n\r", mensjDown[] = "LED 3 APAGADO\n\r";

			gpio_set_level( LED3, !gpio_get_level( LED3 ) );

			if ( gpio_get_level( LED3 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );

		}break;

		case ( led4 +'0' ):{

			char mesjUp[] = "LED 4 ENCENDIDO\n\r", mesjDown[] = "LED 4 APAGADO\n\r";

			gpio_set_level( LED4, !gpio_get_level( LED4 ) );

			if ( gpio_get_level( LED4 ) ) uart_write_bytes( UART_NUM_0, (char*) mesjUp, strlen( mesjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mesjDown, strlen( mesjDown ) );

		}break;

		case ( led5 +'0' ):{

			char mensjUp[] = "LED 5 ENCENDIDO\n\r", mensjDown[] = "LED 5 APAGADO\n\r";

			gpio_set_level( LED5, !gpio_get_level( LED5 ) );

			if ( gpio_get_level( LED5 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ));
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ));

		}break;

		case ( led6 +'0' ):{

			char mensjUp[] = "LED 6 ENCENDIDO\n\r", mensjDown[] = "LED 6 APAGADO\n\r";

			gpio_set_level( LED6, !gpio_get_level( LED6 ) );

			if ( gpio_get_level( LED6 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );

		}break;

		case ( led7 +'0' ):{

			char mensjUp[] = "LED 7 ENCENDIDO\n\r", mensjDown[] = "LED 7 APAGADO\n\r";

			gpio_set_level( LED7, !gpio_get_level( LED7 ) );

			if ( gpio_get_level( LED7 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
			else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );

		}break;

		case ( LedsChange +'0' ):{

			char mensj[] = "TODOS LOS LEDs HAN CAMBIADO DE ESTADO\n\r";

			gpio_set_level( LED1, !gpio_get_level( LED1 ) );
			gpio_set_level( LED2, !gpio_get_level( LED2 ) );
			gpio_set_level( LED3, !gpio_get_level( LED3 ) );
			gpio_set_level( LED4, !gpio_get_level( LED4 ) );
			gpio_set_level( LED5, !gpio_get_level( LED5 ) );
			gpio_set_level( LED6, !gpio_get_level( LED6 ) );
			gpio_set_level( LED7, !gpio_get_level( LED7 ) );

			uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );

		}break;

		default:{

			char mensj[] = "NINGUN LED CAMBIO SU ESTADO\n\r";
			uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );

		}break;
	}

	vTaskDelay( 0 / portTICK_RATE_MS );

}

/**
static void LedControl( char LedSignal ){

	if ( LedSignal == ( ledoff +'0' ) ){

		char mensj[] = "Todos los LEDs han sido apagados\n\r";

		gpio_set_level( LED1, 0 );
		gpio_set_level( LED2, 0 );
		gpio_set_level( LED3, 0 );
		gpio_set_level( LED4, 0 );
		gpio_set_level( LED5, 0 );
		gpio_set_level( LED6, 0 );
		gpio_set_level( LED7, 0 );

		uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );


	}else if ( LedSignal == ( led1 +'0' ) ){

		char mensjUp[] = "LED 1 ENCENDIDO\n\r", mensjDown[] = "LED 1 APAGADO\n\r";

		gpio_set_level( LED1, !gpio_get_level( LED1 ) );

		if ( gpio_get_level( LED1 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );


	}else if ( LedSignal == ( led2 +'0' ) ){

		char mensjUp[] = "LED 2 ENCENDIDO\n\r", mensjDown[] = "LED 2 APAGADO\n\r";

		gpio_set_level( LED2, !gpio_get_level( LED2 ) );

		if ( gpio_get_level( LED2 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );


	}else if ( LedSignal == (  led3 +'0' ) ){

		char mensjUp[] = "LED 3 ENCENDIDO\n\r", mensjDown[] = "LED 3 APAGADO\n\r";

		gpio_set_level( LED3, !gpio_get_level( LED3 ) );

		if ( gpio_get_level( LED3 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );


	}else if ( LedSignal == ( led4 +'0' ) ){

		char mesjUp[] = "LED 4 ENCENDIDO\n\r", mesjDown[] = "LED 4 APAGADO\n\r";

		gpio_set_level( LED4, !gpio_get_level( LED4 ) );

		if ( gpio_get_level( LED4 ) ) uart_write_bytes( UART_NUM_0, (char*) mesjUp, strlen( mesjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mesjDown, strlen( mesjDown ) );


	}else if ( LedSignal == ( led5 +'0' ) ){

		char mensjUp[] = "LED 5 ENCENDIDO\n\r", mensjDown[] = "LED 5 APAGADO\n\r";

		gpio_set_level( LED5, !gpio_get_level( LED5 ) );

		if ( gpio_get_level( LED5 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ));
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ));


	}else if ( LedSignal == ( led6 +'0' ) ){

		char mensjUp[] = "LED 6 ENCENDIDO\n\r", mensjDown[] = "LED 6 APAGADO\n\r";

		gpio_set_level( LED6, !gpio_get_level( LED6 ) );

		if ( gpio_get_level( LED6 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );


	}else if ( LedSignal == ( led7 +'0' ) ){

		char mensjUp[] = "LED 7 ENCENDIDO\n\r", mensjDown[] = "LED 7 APAGADO\n\r";

		gpio_set_level( LED7, !gpio_get_level( LED7 ) );

		if ( gpio_get_level( LED7 ) ) uart_write_bytes( UART_NUM_0, (char*) mensjUp, strlen( mensjUp ) );
		else uart_write_bytes( UART_NUM_0, (char*) mensjDown, strlen( mensjDown ) );


	}else if ( LedSignal == ( LedsChange +'0' ) ){

		char mensj[] = "Todos los LEDs han cambiado de estado\n\r";

		gpio_set_level( LED1, !gpio_get_level( LED1 ) );
		gpio_set_level( LED2, !gpio_get_level( LED2 ) );
		gpio_set_level( LED3, !gpio_get_level( LED3 ) );
		gpio_set_level( LED4, !gpio_get_level( LED4 ) );
		gpio_set_level( LED5, !gpio_get_level( LED5 ) );
		gpio_set_level( LED6, !gpio_get_level( LED6 ) );
		gpio_set_level( LED7, !gpio_get_level( LED7 ) );

		uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );


	}else{

		char mensj[] = "No se detectó ningún cambio\n\r";
		uart_write_bytes( UART_NUM_0, (char*) mensj, strlen( mensj ) );

	}

	vTaskDelay( 50 / portTICK_RATE_MS );

}
**/

void LEDControl(void *P){

	char Rx[1];

	for(;;){

		if ( xQueueReceive( ColaUART, &Rx, 1000 / portTICK_RATE_MS ) == pdTRUE ){

			LedControl( *Rx );

		}

		vTaskDelay( 200 / portTICK_PERIOD_MS );

	}

}



