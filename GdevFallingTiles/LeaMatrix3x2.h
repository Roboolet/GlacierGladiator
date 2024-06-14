#pragma once

// i ended up not using this since it made
// everything unecessarily complicated
class LeaMatrix3x2 {
public:
	LeaVec2 rowI;
	LeaVec2 rowJ;
	LeaVec2 rowK;
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