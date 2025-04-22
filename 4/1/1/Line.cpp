#include"Line.h"

Line::Line(int _x1, int _x2, int _y1, int _y2, int _z1, int _z2) {
	type = "line";
	x1 = _x1, x2 = _x2, y1 = _y1, y2 = _y2, z2 = _z2;
}

void Line::getSides() {
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	sides.insert(std::pair<std::string, int>("a", sqrt(pow(a, 2) + pow(b, 2) + pow(c, 2))));
	std::cout << "a = " << sides["a"] << std::endl;
}

double Line::getSquare() {
	return 0;
}

double Line::getVolume() {
	return 0;
}