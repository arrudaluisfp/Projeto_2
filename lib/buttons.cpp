/*
 * buttons.cpp
 *
 *  Created on: 25 de set de 2019
 *      Author: Jessen
 */


#include <Bounce2.h>
#include "../include/definitions.h"

void buttons_config()
{
	pinMode(p, INPUT);
	pinMode(up, INPUT);
	pinMode(down, INPUT);
	pinMode(set, INPUT);
}

Bounce setBTN = Bounce(); // Instantiate a Bounce object
Bounce pBTN = Bounce();
Bounce upBTN = Bounce();
Bounce downBTN = Bounce();

void debouncer_config()
{
	setBTN.attach(set); //atribuir o pino ao debouncer
	setBTN.interval(25); //setar o intervalo
	pBTN.attach(p);
	pBTN.interval(25);
	upBTN.attach(up);
	upBTN.interval(25);
	downBTN.attach(down);
	downBTN.interval(25);
}

void update_buttons()
{
	setBTN.update();
	pBTN.update();
	upBTN.update();
	downBTN.update();
}

bool click_button_p()
{
	if (pBTN.fell())
		return true;
	else
		return false;
}

bool click_button_up()
{
	if (upBTN.fell())
		return true;
	else
		return false;
}

bool click_button_down()
{
	if (downBTN.fell())
		return true;
	else
		return false;
}

bool click_button_set()
{
	if (setBTN.fell())
		return true;
	else
		return false;
}
