#pragma once
#include <cmath>
#include <string>
#include<windows.h>
#include<Number.h>

#ifdef VECTOR_EXPORTS
#define VECTOR_API __declspec(dllexport)
#else
#define VECTOR_API __declspec(dllimport)
#endif

namespace Math {
	class DoubleVector
	{
	private:
		DoubleNumber x_ = ZERO_DNUMBER;
		DoubleNumber y_ = ZERO_DNUMBER;
	public:

		VECTOR_API DoubleVector();
		VECTOR_API DoubleVector(DoubleNumber x, DoubleNumber y);
		VECTOR_API DoubleNumber CalculateRadialCoordinate();
		VECTOR_API DoubleNumber CalculateAngularCoordinate();
		VECTOR_API DoubleVector operator+(const DoubleVector& vector);

		VECTOR_API std::string ToString();
	};

	const DoubleVector ZERO_DVECTOR(ZERO_DNUMBER, ZERO_DNUMBER);
	const DoubleVector ONE_DVECTOR(ONE_DNUMBER, ONE_DNUMBER);
	
}

extern "C" VECTOR_API void TransformToPolarVector(double x, double y, std::string& result);

