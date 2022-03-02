#ifndef NUMBER_NUMBER_H
#define NUMBER_NUMBER_H
namespace Math{
class Number
{
private:
    double value_ = 0;
public:
    Number() = default;
    Number(double value) : value_(value) {}
    Number operator+(const Number& number);
    Number operator-(const Number& number);
    Number operator*(const Number& number);
    Number operator/(const Number& number);

    double GetValue();
    void SetValue(double value);


};

Number CreateNumber(double value);
const Number ZERO_NUMBER(0);
const Number ONE_NUMBER(1);
}

#endif //NUMBER_NUMBER_H
