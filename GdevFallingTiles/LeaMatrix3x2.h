#pragma once
#include "LeaMath.h"

class LeaMatrix3x2 {
public:
	LeaVec2 rowI, rowJ, rowK;
	LeaMatrix3x2();
	virtual ~LeaMatrix3x2();

	LeaMatrix3x2 operator*(LeaMatrix3x2 _m);
	LeaVec2 operator*(LeaVec2& _m);

private:
	// static methods
	static LeaMatrix3x2* MakeRotator(float _theta);
	static LeaMatrix3x2* MakeScaling(float _x, float _y);
	static LeaMatrix3x2* MakeTranslator(float _x, float _y);
	
};