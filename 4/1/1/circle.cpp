#include"circle.h"

Circle::Circle(int _x1, int _y1, double R, double H) {
	type = "circle";
	x1 = _x1, y1 = _y1;
	radius = R;
	height = H;
}

void Circle::getSides() {
	std::cout << " ";
}

double Circle::getSquare() {
	return M_PI * radius * radius;
}

double Circle::getVolume() {
	return 0;
}