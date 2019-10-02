/*
 * lm35_handler.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */

#include <Arduino.h>
#include "../include/definitions.h"


void LM35_temperature()
{
	float vet[100];
	float Sum = 0;

	for (int i = 0; i < 100; i++) {
		vet[i] = (float(analogRead(lm35)) * 5 / (1023)) / 0.01;
		Sum += vet[i];
	}
	Sum = (Sum / 100);
	current_temperature = Sum;

}
