/*
 * lcd_handler.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */

#include "Arduino.h"
#include "../include/definitions.h"
#include <LiquidCrystal.h>
#include <Bounce2.h>

LiquidCrystal lcd(12, 11, 4, 3, 2, 1);

int screen, heat_pwm_manual, fan_pwm_manual, heat_state, fan_state;
float current_temperature, setpoint, gainH = 15.0, gainF = 15.0;
bool manual_mode;

void lcd_display_config()
{
	//Define o número de colunas e linhas do LCD
	lcd.begin(16, 2);

}

//MAIN SCREEN
void main_screen()
{
	lcd.clear();

	while (screen == main)
	{
		heart_beating();
		update_buttons();

		lcd.setCursor(0, 0);
		lcd.print("SP: ");
		delay(100);
		lcd.print(setpoint, 1);

		LM35_temperature();

		lcd.setCursor(0, 1);
		lcd.print("PV: ");
		lcd.print(current_temperature, 1);

		driver_state = 1;
		driver_read_state();
		controller();
		start();

		if (driver_state == 0)
		{
			lcd.setCursor(10, 0);
			lcd.print("Driver");
			lcd.setCursor(12, 1);
			lcd.print("OFF");
		} else if (driver_state == 1 && heat_state == 0 && fan_state == 0)
		{
			lcd.setCursor(10, 0);
			lcd.print("Driver");
			lcd.setCursor(12, 1);
			lcd.print("ON ");
		}

		if (driver_state == 1 && heat_state == 1 && fan_state == 0)
		{ //if heat on print "Heat ON"
			lcd.setCursor(10, 0);
			lcd.print("Heat ");
			lcd.setCursor(12, 1);
			lcd.print("ON ");
		/* else if (heat_state == 0) { //if heat off print "Heat OFF"
			lcd.setCursor(12, 0);
			lcd.print("Heat");
			lcd.setCursor(12, 1);
			lcd.print("OFF");*/
		} else if (driver_state == 1 && fan_state == 1 && heat_state == 0)
		{ //if fan on print "Fan ON"
			lcd.setCursor(10, 0);
			lcd.print("  Fan ");
			lcd.setCursor(12, 1);
			lcd.print("ON ");
		}

		if (manual_mode == true && heat_state_manual == 1 && fan_state == 0)
		{ //if heat on print "Heat ON"
			lcd.setCursor(10, 0);
			lcd.print("  Heat");
			lcd.setCursor(12, 1);
			lcd.print("ON ");
		/* else if (heat_state == 0) { //if heat off print "Heat OFF"
			lcd.setCursor(12, 0);
			lcd.print("Heat");
			lcd.setCursor(12, 1);
			lcd.print("OFF");*/
		} else if (manual_mode == true && fan_state_manual == 1 && heat_state == 0)
		{ //if fan on print "Fan ON"
			lcd.setCursor(10, 0);
			lcd.print("   Fan ");
			lcd.setCursor(12, 1);
			lcd.print("ON ");
		}
		/* else if (fan_state == 0) { //if fan off print "FAN OFF"
			lcd.setCursor(12, 0);
			lcd.print("Fan ");
			lcd.setCursor(12, 1);
			lcd.print("OFF");
		}*/

		if (click_button_p()) screen = newSP; //if P button pressed change to SETPOINT screen

	}
}

//HEAT GAIN SCREEN
void gainH_screen()
{
	int config_mode = 0;
	lcd.clear();

	while (screen == newGH)
	{
		heart_beating();
		update_buttons();

		lcd.setCursor(0, 0);
		lcd.print("New Prop. Gain H");
		lcd.setCursor(0, 1);
		lcd.print("Kp: ");
		lcd.print(gainH, 1);

		if (click_button_set())
		{
			config_mode = 1;

			while (config_mode == 1)
			{
				gainH_config_update();

				lcd.setCursor(8, 1);
				lcd.print("<-");
				lcd.setCursor(4, 1);
				lcd.print(gainH, 1);

				//BUTTON SET
				if (click_button_set())
				{ //set confirm changes
					lcd.setCursor(8, 1);
					lcd.print("  ");
					config_mode = 0;
				}
			}
		}

		if (click_button_p()) screen = newGF; //if P button pressed change to gainF screen

	}
}

//FAN GAIN SCREEN
void gainF_screen()
{
	lcd.clear();
	int config_mode = 0;

	while (screen == newGF)
	{
		update_buttons();
		heart_beating();

		lcd.setCursor(0, 0);
		lcd.print("New Prop. Gain F");
		lcd.setCursor(0, 1);
		lcd.print("Kp: ");
		lcd.print(gainF, 1);

		if (click_button_set())
		{
			config_mode = 1;

			while (config_mode == 1)
			{
				gainF_config_update();

				lcd.setCursor(8, 1);
				lcd.print("<-");
				lcd.setCursor(4, 1);
				lcd.print(gainF, 1);

				//BUTTON SET
				if (click_button_set())
				{ //set confirm changes
					lcd.setCursor(8, 1);
					lcd.print("  ");
					config_mode = 0;
				}
			}
		}

		if (click_button_p()) screen = setmode; //if P button pressed change to HEAT screen

	}
}


//SETPOINT SCREEN
void setpoint_screen()
{
	lcd.clear();
	int config_mode = 0;

	while (screen == newSP)
	{
		update_buttons();
		heart_beating();

		lcd.setCursor(0, 0);
		lcd.print("New Set Point");
		lcd.setCursor(0, 1);
		lcd.print("SP: ");
		lcd.print(setpoint, 1);

		if (click_button_set())
		{
			config_mode = 1;

			lcd.setCursor(8, 1);
			lcd.print("<-");

			while (config_mode == 1)
			{
				update_buttons();
				//BUTTON UP
				if (click_button_up()) setpoint += 1; //UP increases setpoint
				//BUTTON DOWN
				if (click_button_down()) setpoint -= 1; //DOWN decreases setpoint

				lcd.setCursor(0, 1);
				lcd.print("SP: ");
				lcd.print(setpoint, 1);

				//BUTTON SET
				if (click_button_set())
				{ //set confirm changes
					lcd.setCursor(8, 1);
					lcd.print("  ");
					config_mode = 0;
				}
			}

		}

		if (click_button_p()) screen = newGH; //if P button pressed change to gainH screen
	}
}


//HEAT SCREEN MANUAL FUNCTION
void heat_screen()
{
	lcd.clear();
	int config_mode = 0;

	while (screen == heat)
	{
		update_buttons();
		heart_beating();

		lcd.setCursor(2, 0);
		lcd.print("Manual Mode");
		lcd.setCursor(0, 1);
		lcd.print("Heat: ");
		if (heat_state == 1 || heat_state_manual == 1)
		{
			lcd.setCursor(6, 1);
			lcd.print("ON ");
			lcd.setCursor(11, 1);
			lcd.print(heat_pwm_manual);
			if (heat_pwm_manual == 100)
			{
				lcd.setCursor(14, 1);
				lcd.print("%");
			} else if (heat_pwm_manual >= 10)
			{
				lcd.setCursor(13, 1);
				lcd.print("% ");
			} else if (heat_pwm_manual < 10)
			{
				lcd.setCursor(12, 1);
				lcd.print("%  ");
			}
		} else if (heat_state == 0 || heat_state_manual == 0)
		{
			lcd.setCursor(6, 1);
			lcd.print("OFF");
			lcd.setCursor(11, 1);
			lcd.print("    ");
		}

		if (click_button_set())
		{
			config_mode = 1;

			lcd.setCursor(9, 1);
			lcd.print("<-");

			while (config_mode == 1)
			{
				heat_state_manual_config_update();

				if (heat_state == 1 || heat_state_manual == 1)
				{
					lcd.setCursor(6, 1);
					lcd.print("ON ");
				} else if (heat_state == 0 || heat_state_manual == 0)
				{
					lcd.setCursor(6, 1);
					lcd.print("OFF");
					lcd.setCursor(11, 1);
					lcd.print("    ");
				}

				//BUTTON SET
				if (click_button_set())
				{

					if (heat_state == 1 || heat_state_manual == 1)
					{
						config_mode = 2;

						while (config_mode == 2)
						{

							heat_pwm_manual_config_update();

							lcd.setCursor(9, 1);
							lcd.print("->");
							lcd.setCursor(11, 1);
							lcd.print(heat_pwm_manual);
							if (heat_pwm_manual == 100)
							{
								lcd.setCursor(14, 1);
								lcd.print("%");
							} else if (heat_pwm_manual >= 10)
							{
								lcd.setCursor(13, 1);
								lcd.print("% ");
							} else if (heat_pwm_manual < 10)
							{
								lcd.setCursor(12, 1);
								lcd.print("%  ");
							}

							if (click_button_set())
							{
								config_mode = 0;
								lcd.setCursor(9, 1);
								lcd.print("  ");
							}
						}
					}
					if (heat_state == 0 || heat_state_manual == 0)
					{
						config_mode = 0;
						lcd.setCursor(9, 1);
						lcd.print("  ");
					}
				}
			}
		}

		if (click_button_p()) screen = fan; //if P button pressed change to FAN screen
	}
}


//MANUAL MODE SET SCREEN
void manual_mode_screen()
{
	lcd.clear();
	int config_mode = 0;

	while (screen == setmode)
	{
		update_buttons();
		heart_beating();

		lcd.setCursor(2, 0);
		lcd.print("Manual Mode");
		if (manual_mode == true)
		{
			lcd.setCursor(7, 1);
			lcd.print("ON ");
		} else if (manual_mode == 0)
		{
			lcd.setCursor(7, 1);
			lcd.print("OFF");
		}

		if (click_button_set())
		{
			config_mode = 1;

			lcd.setCursor(10, 1);
			lcd.print("<-");

			while (config_mode == 1)
			{
				manual_mode_config_update();

				if (manual_mode == 1)
				{
					lcd.setCursor(7, 1);
					lcd.print("ON ");
				} else if (manual_mode == 0)
				{
					lcd.setCursor(7, 1);
					lcd.print("OFF");
				}

				//BUTTON SET
				if (click_button_set())
				{ //set confirm changes
					lcd.setCursor(10, 1);
					lcd.print("  ");
					config_mode = 0;
				}
			}

		}

		if (manual_mode == true)
		{
			if (click_button_p()) screen = heat; //if P button pressed with manual_mode ON change to HEAT screen
		} else if (manual_mode == false)
		{
			if (click_button_p()) screen = driver; //if P button pressed with manual_mode OFF change to DRIVER screen
		}
	}

}

//FAN SCREEN MANUAL FUNCTION
void fan_screen()
{
	lcd.clear();
	int config_mode = 0;

	while (screen == fan)
	{
		update_buttons();
		heart_beating();

		lcd.setCursor(2, 0);
		lcd.print("Manual Mode");
		lcd.setCursor(0, 1);
		lcd.print("Fan: ");
		if (fan_state == 1 || fan_state_manual == 1)
		{
			lcd.setCursor(5, 1);
			lcd.print("ON ");
			lcd.setCursor(10, 1);
			lcd.print(fan_pwm_manual);
			lcd.setCursor(13, 1);
			if (fan_pwm_manual == 100)
			{
				lcd.setCursor(13, 1);
				lcd.print("%");
			} else if (fan_pwm_manual >= 10)
			{
				lcd.setCursor(12, 1);
				lcd.print("% ");
			} else if (fan_pwm_manual < 10)
			{
				lcd.setCursor(11, 1);
				lcd.print("%  ");
			}
		} else if (fan_state == 0 || fan_state_manual == 0)
		{
			lcd.setCursor(5, 1);
			lcd.print("OFF");
			lcd.setCursor(10, 1);
			lcd.print("    ");
		}

		if (click_button_set())
		{
			config_mode = 1;

			lcd.setCursor(8, 1);
			lcd.print("<-");

			while (config_mode == 1)
			{
				fan_state_manual_config_update();

				if (fan_state == 1 || fan_state_manual == 1)
				{
					lcd.setCursor(5, 1);
					lcd.print("ON ");
				} else if (fan_state == 0 || fan_state_manual == 0)
				{
					lcd.setCursor(5, 1);
					lcd.print("OFF");
					lcd.setCursor(10, 1);
					lcd.print("    ");
				}

				//BUTTON SET
				if (click_button_set())
				{

					if (fan_state == 1 || fan_state_manual == 1)
					{
						config_mode = 2;

						while (config_mode == 2)
						{
							fan_pwm_manual_config_update();

							lcd.setCursor(8, 1);
							lcd.print("->");
							lcd.setCursor(10, 1);
							lcd.print(fan_pwm_manual);
							if (fan_pwm_manual == 100)
							{
								lcd.setCursor(13, 1);
								lcd.print("%");
							} else if (fan_pwm_manual >= 10)
							{
								lcd.setCursor(12, 1);
								lcd.print("% ");
							} else if (fan_pwm_manual < 10)
							{
								lcd.setCursor(11, 1);
								lcd.print("%  ");
							}

							if (click_button_set())
							{
								config_mode = 0;
								lcd.setCursor(8, 1);
								lcd.print("  ");
							}
						}
					}
					if (fan_state == 0 || fan_state_manual == 0)
					{
						config_mode = 0;
						lcd.setCursor(8, 1);
						lcd.print("  ");
					}
				}
			}
		}

		if (click_button_p()) screen = driver; //if P button pressed change to DRIVER screen
	}
}

//DRIVER SCREEN MANUAL FUNCTION
void driver_screen()
{
	int config_mode = 0;
	lcd.clear();

	while (screen == driver)
	{
		heart_beating();
		update_buttons();

		lcd.setCursor(2, 0);
		lcd.print("Driver Status");
		if (driver_state == 1)
		{
			lcd.setCursor(4, 1);
			lcd.print("Enabled ");
		} else if (driver_state == 0)
		{
			lcd.setCursor(4, 1);
			lcd.print("Disabled");
		}

		if (click_button_set())
		{
			config_mode = 1;

			while (config_mode == 1)
			{
				driver_state_config_update();

				lcd.setCursor(12, 1);
				lcd.print("<-");
				if (driver_state == 1)
				{
					lcd.setCursor(4, 1);
					lcd.print("Enabled ");
				} else if (driver_state == 0)
				{
					lcd.setCursor(4, 1);
					lcd.print("Disabled");
				}

				//BUTTON SET
				if (click_button_set())
				{ //set confirm changes
					lcd.setCursor(12, 1);
					lcd.print("  ");
					driver_read_state();
					config_mode = 0;
				}
			}
		}

		if (click_button_p()) screen = main; //if P button pressed change to MAIN screen
	}
}

void screens()
{
	switch (screen)
	{
	case main:
		main_screen();
		break;

	case newSP:
		setpoint_screen();
		break;

	case newGH:
		gainH_screen();
		break;

	case newGF:
		gainF_screen();
		break;

	case setmode:
		manual_mode_screen();
		break;

	case heat:
		heat_screen();
		break;

	case fan:
		fan_screen();
		break;

	case driver:
		driver_screen();
		break;
	}

}

