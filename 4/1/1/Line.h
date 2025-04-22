#pragma once
#include"shape.h"

class Line :public Shape {
public:
	Line(int _x1, int _x2, int _y1, int _y2, int _z1, int _z2);

	void getSides() override;
	double getSquare() override;
	double getVolume() override;

protected:
	std::map<std::string,int> sides;
};