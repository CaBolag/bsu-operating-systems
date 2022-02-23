#pragma once

namespace Math {
	class DoubleNumber
	{
	private:
		double value_ = 0;
	public:
		DoubleNumber() = default;
		DoubleNumber(double value) : value_(value) {}
		DoubleNumber operator+(const DoubleNumber& number);
		DoubleNumber operator-(const DoubleNumber& number);
		DoubleNumber operator*(const DoubleNumber& number);
		DoubleNumber operator/(const DoubleNumber& number);

		double GetValue();
		void SetValue(double value);


	};

	DoubleNumber CreateNumber(double value);
	const DoubleNumber ZERO_DNUMBER(0);
	const DoubleNumber ONE_DNUMBER(1);
}