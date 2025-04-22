#pragma once
#include"Line.h"

class Rectangle : public Line {
public:
	Rectangle(int _x1, int _x2, int _x3, int _x4, int _y1, int _y2, int _y3, int _y4);

	void getSides() override;
	double getSquare() override;
	double getVolume() override;
};