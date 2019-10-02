/*
 * definitions.h
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

#define DELAY_HEART_BEATING 500
#define PIN_HEART_BEATING 7

/* Pins */
#define lm35  	   A0
#define ENABLE	   0
#define in1		   5
#define in2		   6
#define p		   8
#define up		   9
#define down	   10
#define set		   13

/* Screens */
#define main	    0
#define newSP	    1
#define newGH	    2
#define newGF	    3
#define setmode		4
#define heat 	    5
#define fan		    6
#define driver	    7


/* External Variables */
extern float current_temperature, setpoint, gainH, gainF;
extern bool manual_mode;
extern int heat_pwm_manual, fan_pwm_manual, heat_state, fan_state, heat_state_manual, fan_state_manual, driver_state, screen, inH, inF;

/* LCD Handler */
void lcd_display_config();
void main_screen();
void setpoint_screen();
void gainH_screen();
void gainF_screen();
void manual_mode_screen();
void heat_screen();
void fan_screen();
void driver_screen();
void screens();

/* Controller */
void controller_config();
void controller();
void heat_state_manual_config_update();
void heat_pwm_manual_config_update();
void heat_read_pwm();
void fan_state_manual_config_update();
void fan_pwm_manual_config_update();
void fan_read_pwm();
void driver_state_config_update();
void driver_read_state();
void gainH_config_update();
void gainF_config_update();
void manual_mode_config_update();
void start();

/* LM35 handler */
void LM35_temperature();

/* Button Handler */
bool click_button_p();
bool click_button_set();
bool click_button_up();
bool click_button_down();
void buttons_config();
void debouncer_config();
void update_buttons();

/* Main */
extern void heart_beating();



#endif /* DEFINITIONS_H_ */
