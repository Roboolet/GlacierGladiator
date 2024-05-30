#include "LeaMath.h"
#include <cmath>

LeaMatrix3x2::LeaMatrix3x2() {
	// create the identity
	// the third row is omitted since it doesnt serve a function for this game
	rowI = new LeaVec2(1, 0);
	rowJ = new LeaVec2(0, 1);
	rowK = new LeaVec2();
}

LeaMatrix3x2::~LeaMatrix3x2() {
}

LeaMatrix3x2 LeaMatrix3x2::operator*(LeaMatrix3x2 _m) {

}
LeaVec2 LeaMatrix3x2::operator* (LeaVec2& _v)
{
	_v.x = _v.x * this->rowI.x + _v.y * this->rowJ.x + this->rowK.x;
	_v.y = _v.x * this->rowI.y + _v.y * this->rowJ.y + this->rowK.y;
	return _v;
}

LeaMatrix3x2* LeaMatrix3x2::MakeRotator(float _theta) {
	LeaMatrix3x2* mat = new LeaMatrix3x2();
	mat->rowI.x = cosf(_theta);
	mat->rowI.y = sinf(_theta);
	mat->rowJ.x = -sinf(_theta);
	mat->rowJ.y = cosf(_theta);
	return mat;
}

LeaMatrix3x2* LeaMatrix3x2::MakeScaling(float _x, float _y) {
	LeaMatrix3x2* mat = new LeaMatrix3x2();
	mat->rowI.x = _x;
	mat->rowJ.y = _y;
	return mat;
}

LeaMatrix3x2* LeaMatrix3x2::MakeTranslator(float _x, float _y) {
	LeaMatrix3x2* mat = new LeaMatrix3x2();
	mat->rowK.x = _x;
	mat->rowK.y = _y;
	return mat;
}