#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int trige_yes (double a, double b, double c) {
	if ((a*a + b*b == c*c) | (c*c + a*a == b*b) | (c*c + b*b == a*a)) return 1;
	else return 0;
}

double trige_perimetr(double a, double b, double c) {
	double p;
	p = a + b + c;
	return p;
}

double trige_ploschad(double a, double b, double c) {
	double p;
	p = a + b + c;
	double s;
	s = sqrt((p/2) * (p/2 - a) * (p/2 - b) * (p/2 - c));
	return s;
}

double trige_heigth(double a, double b, double c, int i) {
	double p, s, h;
	p = a + b + c;
	s = sqrt((p/2) * (p/2 - a) * (p/2 - b) * (p/2 - c));
	switch(i) {
		case 1:
			h = (2*s)/a;
		case 2:
			h = (2*s)/b;
		case 3:
			h = (2*s)/c;
		default: 
			return 0;
	}
	return h;
}
