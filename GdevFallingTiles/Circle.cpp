#include "Circle.h"
#include <iostream>

Circle::Circle(int x, int y, int rad) : xpos(x), ypos(y), radius(rad) {

}

void Circle::draw() {
	std::cout << "(" << xpos << "," << ypos << ")" << std::endl;
}