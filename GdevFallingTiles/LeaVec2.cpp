#include "LeaVec2.h"
#include <cmath>

LeaVec2::LeaVec2() : x(0), y(0) {}
LeaVec2::LeaVec2(float _x, float _y) : x(_x), y(_y) {}
LeaVec2::LeaVec2(LeaVec2* _original) : x(_original->x), y(_original->y) {}

void LeaVec2::Set(float _x, float _y) { x = _x; y = _y; }

float LeaVec2::MagnitudeSqr() { return x*x + y*y; }
float LeaVec2::Magnitude() { return sqrt(x*x + y*y); }
LeaVec2& LeaVec2::Normalized() {
	float mag = Magnitude();
	if (mag != 0) {
		x = x / mag; y = y / mag;
		return *this;
	}
	x = 0; y = 0;
	return *this;
}
float LeaVec2::Distance(LeaVec2 _other) { return LeaVec2(x - _other.x, y - _other.y).Magnitude(); }
float LeaVec2::DistanceSqr(LeaVec2 _other) { return LeaVec2(x - _other.x, y - _other.y).MagnitudeSqr(); }
float LeaVec2::Dot(LeaVec2 _other) { return (x * _other.x + y * _other.y); }

// operator definitions
const LeaVec2 LeaVec2::operator* (float _scalar)
{
	return LeaVec2(this->x * _scalar, this->y * _scalar);
}

const LeaVec2 LeaVec2::operator+ (LeaVec2 _value)
{
	return LeaVec2(this->x + _value.x, this->y + _value.y);
}
const LeaVec2 LeaVec2::operator- (LeaVec2 _value)
{
	return LeaVec2(this->x - _value.x, this->y - _value.y);
}
const LeaVec2 LeaVec2::operator/ (float _value)
{
	float xn = 0;
	float yn = 0;
	if (this->x != 0 && _value != 0) { xn = this->x / _value; }
	if (this->y != 0 && _value != 0) { yn = this->y / _value; }
	return LeaVec2(xn, yn);
}
