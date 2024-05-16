#include "LeaVec2.h"
#include <cmath>

LeaVec2::LeaVec2() : x(0), y(0) {}
LeaVec2::LeaVec2(float _x, float _y) : x(_x), y(_y) {}
LeaVec2::LeaVec2(LeaVec2& original) : x(original.x), y(original.y) {}

void LeaVec2::Set(float _x, float _y) {	x = _x; y = _y;}

float LeaVec2::MagnitudeSqr() { return pow(x,2) + pow(y,2); }
float LeaVec2::Magnitude() { return sqrt(pow(x, 2) + pow(y, 2)); }
LeaVec2 & LeaVec2::Normalized() {
	float mag = Magnitude();
	if (mag != 0) {
		x = x / mag; y = y / mag;
		return *this;
	}
	x = 0; y = 0;
	return *this;
}
float LeaVec2::Distance(LeaVec2 other) { return LeaVec2(x - other.x, y - other.y).Magnitude(); }
float LeaVec2::Distance(LeaVec2 other) { return LeaVec2(x - other.x, y - other.y).MagnitudeSqr(); }
float LeaVec2::Dot(LeaVec2 other) { return (x * other.x + y * other.y); }