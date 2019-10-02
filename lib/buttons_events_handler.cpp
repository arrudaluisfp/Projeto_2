/*
 * buttons_events_handler.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */

#include <Arduino.h>
#include "../include/definitions.h"

int heat_state_manual, fan_state_manual;

void heat_state_manual_config_update()
{
	update_buttons();

	if (click_button_p())
	{
		if(heat_state_manual == 1) heat_state_manual = 0;
		else
		{
			heat_state_manual = 1;
			fan_state_manual = 0;
			fan_state = 0;
			heat_state = 0;
		}
	}

}


void fan_pwm_manual_config_update()
{
	update_buttons();

	if (click_button_up()) {
		if (fan_pwm_manual < 100)
			fan_pwm_manual += 10; //UP increases pwm
	}

	if (click_button_down()) {
		if (fan_pwm_manual > 0)
			fan_pwm_manual -= 10; //DOWN decreases pwm
	}
}

void heat_pwm_manual_config_update()
{
	update_buttons();

	if (click_button_up()) {
		if (heat_pwm_manual < 100)
			heat_pwm_manual += 5; //UP increases pwm
	}

	if (click_button_down()) {
		if (heat_pwm_manual > 0)
			heat_pwm_manual -= 5; //DOWN decreases pwm
	}
}

void manual_mode_config_update()
{
	update_buttons();

	if (click_button_p())
	{
		if(manual_mode == true) manual_mode = false;
		else manual_mode = true;
	}
}

void driver_state_config_update()
{
	update_buttons();

	if (click_button_p())
	{
		if(driver_state == 1) driver_state = 0;
		else driver_state = 1;
	}
}

void gainH_config_update()
{
	update_buttons();

	if (click_button_up()) gainH += 1; //UP increases gainH

	if (click_button_down())
	{
		gainH -= 1; //DOWN decreases gainH
		if(gainH < 0) gainH = 0;
	}
}

void gainF_config_update()
{
	update_buttons();

	if (click_button_up()) gainF += 1; //UP increases gainF

	if (click_button_down())
	{
		gainF -= 1; //DOWN decreases gainF
		if(gainF < 0) gainF = 0;
	}

}

void fan_state_manual_config_update()
{
	update_buttons();

	if (click_button_p())
	{
		if(fan_state_manual == 1) fan_state_manual = 0;
		else
		{
			fan_state_manual = 1;
			heat_state_manual = 0;
			fan_state = 0;
			heat_state = 0;
		}
	}
}
