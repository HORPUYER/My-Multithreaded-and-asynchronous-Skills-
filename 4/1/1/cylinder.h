#pragma once
#include"circle.h"

class Cylinder :public Circle {
public:
	Cylinder(int _x1, int _y1, double H, double R);

	void getSides() override;
	double getSquare() override;
	double getVolume() override;
};