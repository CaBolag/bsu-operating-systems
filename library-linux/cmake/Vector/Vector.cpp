#include "Vector.h"

Math::Vector::Vector() {
    x_ = Number(0);
    y_ = Number(0);
}

Math::Vector::Vector(Number x, Number y) {
    x_ = x;
    y_ = y;
}

Math::Number Math::Vector::CalculateRadialCoordinate() {
    return Number(sqrt(pow(x_.GetValue(), 2) + pow(y_.GetValue(), 2)));
}

Math::Number Math::Vector::CalculateAngularCoordinate() {
    Number radius = CalculateRadialCoordinate();
    if (radius.GetValue() == 0) {
        return ZERO_NUMBER;
    }
    return Number(asin(x_.GetValue() / radius.GetValue()));
}


Math::Vector Math::Vector::operator+(const Vector& vector) {
    return Vector(x_ + vector.x_, y_ + vector.y_);
}


std::string Math::Vector::ToString() {
    std::string result;
    result += "x = " + std::to_string(x_.GetValue())
              + ", y = " + std::to_string(y_.GetValue())
              + ", r = " + std::to_string(CalculateRadialCoordinate().GetValue())
              + ", phi = " + std::to_string(CalculateAngularCoordinate().GetValue())
              + "\n";
    return result;
}

void TransformToPolarVector(double x, double y, std::string& result) {
    Math::Number number1(x);
    Math::Number number2(y);
    Math::Vector vector(number1, number2);
    result=vector.ToString();
}
