#include "pch.h"
#include "Number.h"

DoubleNumber DoubleNumber::operator+(const DoubleNumber& number) {
	return DoubleNumber(this->value_ + number.value_);
}

DoubleNumber DoubleNumber::operator-(const DoubleNumber& number) {
	return DoubleNumber(this->value_ - number.value_);
}
DoubleNumber DoubleNumber::operator/(const DoubleNumber& number) {
	return DoubleNumber(this->value_ / number.value_);
}
DoubleNumber DoubleNumber::operator*(const DoubleNumber& number) {
	return DoubleNumber(this->value_ * number.value_);
}

void DoubleNumber::SetValue(double number) {
	this->value_ = number;
}

double DoubleNumber::GetValue() {
	return this->value_;
}

DoubleNumber CreateNumber(double value) {
	return DoubleNumber(value);
}
