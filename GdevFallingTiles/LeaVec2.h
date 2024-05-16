#pragma once


class LeaVec2 {
public:
	// constructors
	LeaVec2(void);
	LeaVec2(float _x, float _y);
	LeaVec2(LeaVec2& _original);

	// members
	float x;
	float y;

	// useful methods
	void Set(float _x, float _y);
	float MagnitudeSqr();
	float Magnitude();
	LeaVec2& Normalized();
	float Distance(LeaVec2 _other);
	float DistanceSqr(LeaVec2 _other);
	float Dot(LeaVec2 _other);

	// basic operators
	LeaVec2 Mul(float _scalar);
	LeaVec2 Add(float _value);
	LeaVec2 Sub(float _value);
	LeaVec2 Div(float _value);
};
