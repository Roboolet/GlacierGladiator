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
LeaVec2* LeaVec2::operator* (float _scalar)
{
	this->x = this->x * _scalar;
	this->y = this->y * _scalar;
	return this;
}
LeaVec2* LeaVec2::operator* (LeaMatrix3x2 _m)
{
	this->x = this->x * _m.rowI.x + this->y * _m.rowJ.x + _m.rowK.x;
	this->y = this->x * _m.rowI.y + this->y * _m.rowJ.y + _m.rowK.y;
	return this;
}
LeaVec2* LeaVec2::operator+ (LeaVec2 _value)
{
	this->x + _value.x;
	this->y + _value.y;
	return this;
}
LeaVec2* LeaVec2::operator- (LeaVec2 _value)
{
	this->x - _value.x;
	this->y - _value.y;
	return this;
}
LeaVec2* LeaVec2::operator/ (float _value)
{
	if (this->x != 0 && _value != 0) { this->x = this->x / _value; }
	if (this->y != 0 && _value != 0) { this->y = this->y / _value; }
	return this;
}
