#pragma once
#include"parallelepiped.h"

class Circle :public Parallelepiped {
public:
	Circle(int _x1, int _y1, double R, double H);

	void getSides() override;
	double getSquare() override;
	double getVolume() override;

protected:
	double radius;
	double height;
};