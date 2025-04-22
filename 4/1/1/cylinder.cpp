#include"cylinder.h"

Cylinder::Cylinder(int _x1, int _y1, double R, double H) {
	type = "circle";
	x1 = _x1, y1 = _y1;
	radius = R;
	height = H;
}

void Cylinder::getSides() {
	std::cout << " ";
}

double Cylinder::getSquare() {
	return M_PI * radius * radius + 2 * radius * height;
}

double Cylinder::getVolume() {
	return M_PI * radius * radius * height;
}