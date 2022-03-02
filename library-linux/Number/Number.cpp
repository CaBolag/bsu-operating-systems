#include "Number.h"


Math::Number Math::Number::operator+(const Number& number) {
    return Number(this->value_ + number.value_);
}

Math::Number Math::Number::operator-(const Number& number) {
    return Number(this->value_ - number.value_);
}
Math::Number Math::Number::operator/(const Number& number) {
    return Number(this->value_ / number.value_);
}
Math::Number Math::Number::operator*(const Number& number) {
    return Number(this->value_ * number.value_);
}

void Math::Number::SetValue(double number) {
    this->value_ = number;
}

double Math::Number::GetValue() {
    return this->value_;
}

Math::Number Math::CreateNumber(double value) {
    return Math::Number(value);
}