#ifndef VECTOR_VECTOR_H
#define VECTOR_VECTOR_H

#include <cmath>
#include <string>
#include<Number.h>


namespace Math {
    class Vector
    {
    private:
        Number x_ = ZERO_NUMBER;
        Number y_ = ZERO_NUMBER;
    public:

        Vector();
        Vector(Number x, Number y);
        Number CalculateRadialCoordinate();
        Number CalculateAngularCoordinate();
        Vector operator+(const Vector& vector);

        std::string ToString();
    };

    const Vector ZERO_VECTOR(ZERO_NUMBER, ZERO_NUMBER);
    const Vector ONE_VECTOR(ONE_NUMBER, ONE_NUMBER);

}

void TransformToPolarVector(double x, double y, std::string& result);

#endif //VECTOR_VECTOR_H
