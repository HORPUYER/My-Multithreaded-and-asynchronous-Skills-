#include <iostream>
#include<vector>
#include"shape.h"
#include"Line.h"
#include"rectangle.h"
#include"parallelepiped.h"
#include"circle.h"

int main() {
	Line l(1, 6, 2, 2, 3, 3);
	l.getSides();
	Rectangle R(1, 2, 3, 4, 5, 6, 7, 8);
	R.getSides();
	Parallelepiped P(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12,1,2,3,4,5,6,7,8,9,10,11,12);

}