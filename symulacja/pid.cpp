#include "pid.h"


float PID::steruj(float dT)
{
	float tempAktualna = pokoj.getTemperatura();
	float uchyb = zadanaTemperatura - tempAktualna;
	float Up = Kp * uchyb;
	uchybCalka += uchyb*dT;
	if (uchybCalka > 1000.0) uchybCalka = 1000.0;
	else if (uchybCalka < -1000.0) uchybCalka = -1000.0;
	float Ui = Ki * uchybCalka;
	float deltaUchyb = (uchyb - uchybPoprzedni) / dT;
	float Ud = Kd * deltaUchyb;
	uchybPoprzedni = uchyb;
	return Up + Ui + Ud;
}
