#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double trige_perimetr(double a, double b, double c) {
	if ((a*a + b*b == c*c) | (c*c + a*a == b*b) | (c*c + b*b == a*a)) {
		double p;
		p = a + b + c;
		return p;
	}
	else {
		return -1;
	}
}

double trige_ploschad(double a, double b, double c) {
	if ((a*a + b*b == c*c) | (c*c + a*a == b*b) | (c*c + b*b == a*a)) {
		double s;
		s = sqrt((p/2) * (p/2 - a) * (p/2 - b) * (p/2 - c));
		return s;
	}
	else {
		return -1;
	}
}
