#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<math.h>
#include"fa17.h"

double ResoFrequ(double dC, double dL, double dR)
{
	if (dL <= (dC * dR * dR))
	{
		return -1;
	}
	double R0, Omg0;
	
	R0 = dL / (dR * dC);
	Omg0 = sqrt((R0 - dR) / (dL * dC * R0));

	return (Omg0 / (2 * 3.14));
	
}

