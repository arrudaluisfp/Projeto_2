/*
 * definitions.h
 *
 *  Created on: 18 de set de 2019
 *      Author: Jessen
 */

#include "Arduino.h"
#include "../include/definitions.h"

int driver_state;

void heart_beating()
{
	static unsigned long int millis_heart_beating = 0;

	if(driver_state == 1)
	{
		if (millis()-millis_heart_beating >= 500)
		{

			millis_heart_beating = millis();
			digitalWrite(7, !digitalRead(7));
		}
	}
	else if(driver_state == 0) digitalWrite(7, HIGH);

}


void setup()
{
	buttons_config();
	debouncer_config();
	controller_config();
	lcd_display_config();
}

void loop()
{
	screens();
}
