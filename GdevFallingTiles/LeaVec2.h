#pragma once

	struct LeaVec2 {
	public:
		// constructors
		LeaVec2(void);
		LeaVec2(float _x, float _y);
		LeaVec2(LeaVec2* _original);

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
		const LeaVec2 operator *(float _scalar);
		const LeaVec2 operator +(LeaVec2 _value);
		const LeaVec2 operator -(LeaVec2 _value);
		const LeaVec2 operator /(float _value);
	};
