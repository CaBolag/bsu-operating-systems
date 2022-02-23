#include "pch.h"
#include "Vector.h"

Math::DoubleVector::DoubleVector() {
		x_ = DoubleNumber(0);
		y_ = DoubleNumber(0);
	}

Math::DoubleVector::DoubleVector(DoubleNumber x, DoubleNumber y) {
		x_ = x;
		y_ = y;
	}

Math::DoubleNumber Math::DoubleVector::CalculateRadialCoordinate() {
		return DoubleNumber(sqrt(pow(x_.GetValue(), 2) + pow(y_.GetValue(), 2)));
	}

Math::DoubleNumber Math::DoubleVector::CalculateAngularCoordinate() {
		DoubleNumber radius = CalculateRadialCoordinate();
		if (radius.GetValue() == 0) {
			return ZERO_DNUMBER;
		}
		return DoubleNumber(asin(x_.GetValue() / radius.GetValue()));
	}


Math::DoubleVector Math::DoubleVector::operator+(const DoubleVector& vector) {
		return DoubleVector(x_ + vector.x_, y_ + vector.y_);
	}


std::string Math::DoubleVector::ToString() {
		std::string result;
		result += "x = " + std::to_string(x_.GetValue())
			+ ", y = " + std::to_string(y_.GetValue())
			+ ", r = " + std::to_string(CalculateRadialCoordinate().GetValue())
			+ ", phi = " + std::to_string(CalculateAngularCoordinate().GetValue())
			+ "\n";
		return result;
	}

void TransformToPolarVector(double x, double y, std::string& result) {
	Math::DoubleNumber d_number1(x);
	Math::DoubleNumber d_number2(y);
	Math::DoubleVector vector(d_number1, d_number2);
	result=vector.ToString();
}

