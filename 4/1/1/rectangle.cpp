#include"rectangle.h"

Rectangle::Rectangle(int _x1, int _x2, int _x3, int _x4, int _y1, int _y2, int _y3, int _y4) {
	type = "rectangle";
	x1 = _x1, x2 = _x2, x3 = _x3, x4 = _x4, y1 = _y1, y2 = _y2, y3 = _y3, y4 = _y4;
}

void Rectangle::getSides() {
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(x3 - x4);
	int d = abs(y3 - y4);
	sides.insert(std::pair<std::string, int>("a", a));
	sides.insert(std::pair<std::string, int>("b", b));
	sides.insert(std::pair<std::string, int>("c", c));
	sides.insert(std::pair<std::string, int>("d", d));

	std::cout << "a = " << sides["a"] << " b = " << sides["b"] << " c = " << sides["c"] << " d = " << sides["d"] << std::endl;
}

double Rectangle::getSquare() {
	return sides["a"] * sides["b"];
}

double Rectangle::getVolume() {
	return 0;
}
