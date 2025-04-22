#include"parallelepiped.h"

Parallelepiped::Parallelepiped(int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8) {
	type = "parallelepiped";
	x1 = _x1, x2 = _x2, x3 = _x3, x4 = _x4, x5 = _x5, x6 = _x6, x7 = _x7, y8 = _x8, y1 = _y1, y2 = _y2, y3 = _y3, y4 = _y4, y5 = _y5, y6 = _y6, y7 = _y7, y8 = _y8;
}

void Parallelepiped::getSides() {
	int a = abs(x1 - x2);
	int b = abs(y1 - y2);
	int c = abs(z1 - z2);
	int d = abs(x3 - x4);
	int e = abs(y3 - y4);
	int f = abs(z3 - z4);
	int g = abs(x5 - x6);
	int h = abs(y5 - y6);
	int i = abs(z5 - z6);
	int j = abs(x7 - x8);
	int k = abs(y7 - y8);
	int l = abs(z7 - z8);

	sides.insert(std::pair<std::string, int>("a", a));
	sides.insert(std::pair<std::string, int>("b", b));
	sides.insert(std::pair<std::string, int>("c", c));
	sides.insert(std::pair<std::string, int>("d", d));
	sides.insert(std::pair<std::string, int>("e", e));
	sides.insert(std::pair<std::string, int>("f", f));
	sides.insert(std::pair<std::string, int>("g", g));
	sides.insert(std::pair<std::string, int>("h", h));
	sides.insert(std::pair<std::string, int>("i", i));
	sides.insert(std::pair<std::string, int>("j", j));
	sides.insert(std::pair<std::string, int>("k", k));
	sides.insert(std::pair<std::string, int>("l", l));

	std::cout << "a = " << sides["a"] << "b = " << sides["b"] << "c = " << sides["c"] << "d = " << sides["d"] << "e = " << sides["e"] << "f = " << sides["f"] << "g = " << sides["g"] << "h = " << sides["h"] << "i = " << sides["i"] << "j = " << sides["j"] << "k = " << sides["k"] << "l = " << sides["l"] << std::endl;
}

double Parallelepiped::getSquare() {
	return 2 * sides["a"] * sides["b"] + 2 * sides["a"] * sides["c"] + 2 * sides["b"] * sides["c"];
}

double Parallelepiped::getVolume() {
	return sides["a"] * sides["b"] * sides["c"];
}