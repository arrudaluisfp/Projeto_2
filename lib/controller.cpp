/*
 * controller.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */

#include <Arduino.h>
#include "../include/definitions.h"

int inH, inF;

void controller_config()
{
	pinMode(ENABLE, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(PIN_HEART_BEATING, OUTPUT);
	setpoint = 23.0;
	analogWrite(in1, 0);
	analogWrite(in2, 0);
	digitalWrite(ENABLE, 0);
}

void driver_read_state()
{
	digitalWrite(ENABLE, driver_state);
}

void controller()
{
	inH = (setpoint - current_temperature) * gainH;
	if(inH > 70) inH = 70;
	inF = (setpoint + current_temperature) * gainF;
	if(inF > 255) inF = 255;
	if(inF < 56) inF = 56;
}

void start()
{
	if(current_temperature < setpoint && manual_mode == false)
	{
		heat_state=1;
		fan_state=0;
		heat_read_pwm();
	}
	else if(current_temperature >= setpoint && manual_mode == false)
	{
		heat_state=0;
		fan_state=1;
		fan_read_pwm();
	}
	else if(manual_mode == true)
	{
		if (heat_state_manual == 1 && fan_state_manual == 0)
		{
			heat_pwm_manual = map(heat_pwm_manual, 0, 100, 0, 70);
			analogWrite(in1, heat_pwm_manual);
			analogWrite(in2, 0);
		}
		else if (fan_state_manual == 1 && heat_state_manual == 0) {
			fan_pwm_manual = map(fan_pwm_manual, 0, 100, 56, 255);
			analogWrite(in2, fan_pwm_manual);
			analogWrite(in1, 0);
		}
	}
}

void heat_read_pwm()
{
	if (manual_mode == false) {
		analogWrite(in1, inH);
		analogWrite(in2, 0);
	} else if (manual_mode == true) {
		heat_pwm_manual = map(heat_pwm_manual, 0, 100, 0, 70);
		analogWrite(in1, heat_pwm_manual);
		analogWrite(in2, 0);
	}
}

void fan_read_pwm()
{
	if (manual_mode == false) {
		analogWrite(in2, inF);
		analogWrite(in1, 0);
	} else if (manual_mode == true) {
		if (fan_state == 1 && heat_state == 0) {
			fan_pwm_manual = map(fan_pwm_manual, 0, 100, 56, 255);
			analogWrite(in2, fan_pwm_manual);
			analogWrite(in1, 0);
		}
	}
}


