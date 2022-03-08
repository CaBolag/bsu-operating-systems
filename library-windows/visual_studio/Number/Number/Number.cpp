#include "pch.h"
#include "Number.h"


Math::DoubleNumber Math::DoubleNumber::operator+(const DoubleNumber& number) {
		return DoubleNumber(this->value_ + number.value_);
	}

Math::DoubleNumber Math::DoubleNumber::operator-(const DoubleNumber& number) {
		return DoubleNumber(this->value_ - number.value_);
	}
Math::DoubleNumber Math::DoubleNumber::operator/(const DoubleNumber& number) {
		return DoubleNumber(this->value_ / number.value_);
	}
Math::DoubleNumber Math::DoubleNumber::operator*(const DoubleNumber& number) {
		return DoubleNumber(this->value_ * number.value_);
	}

void Math::DoubleNumber::SetValue(double number) {
	this->value_ = number;
}

double Math::DoubleNumber::GetValue() {
	return this->value_;
}

Math::DoubleNumber Math::CreateNumber(double value) {
	return Math::DoubleNumber(value);
}