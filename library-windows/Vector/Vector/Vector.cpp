#include "pch.h"
#include "Vector.h"

	DoubleVector::DoubleVector() {
		x_ = DoubleNumber(0);
		y_ = DoubleNumber(0);
	}

	DoubleVector::DoubleVector(DoubleNumber x, DoubleNumber y) {
		x_ = x;
		y_ = y;
	}

	DoubleNumber DoubleVector::CalculateRadialCoordinate() {
		return DoubleNumber(sqrt(pow(x_.GetValue(), 2) + pow(y_.GetValue(), 2)));
	}

	DoubleNumber DoubleVector::CalculateAngularCoordinate() {
		DoubleNumber radius = CalculateRadialCoordinate();
		if (radius.GetValue() == 0) {
			return ZERO_DNUMBER;
		}
		return DoubleNumber(asin(x_.GetValue()/radius.GetValue()));
	}


	DoubleVector DoubleVector::operator+(const DoubleVector& vector) {
		return DoubleVector(x_ + vector.x_, y_ + vector.y_);
	}


	std::string DoubleVector::ToString() {
		std::string result;
		result += "x = " + std::to_string(x_.GetValue())
			+ ", y = " + std::to_string(y_.GetValue())
			+ ", r = " + std::to_string(CalculateRadialCoordinate().GetValue())
			+ ", phi = " + std::to_string(CalculateAngularCoordinate().GetValue())
			+"\n";
		return result;
	}

	//std::string TransformToPolarVector(double x, double y) {
	//	DoubleVector vector(DoubleNumber(x), DoubleNumber(y));
	//	return vector.ToString();
	//}