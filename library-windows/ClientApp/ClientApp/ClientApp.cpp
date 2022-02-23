#include <iostream>
#include<Vector.h>

int main()
{

    DoubleVector vector1(CreateNumber(1.),ZERO_DNUMBER);
    DoubleVector one_vector = ONE_DVECTOR;
    DoubleVector result_vector = vector1 + one_vector;
    std::cout << "vector1:\n "<<vector1.ToString();
    std::cout << "vector2:\n "<<one_vector.ToString();
    std::cout <<"vector1 + vector2:\n " <<result_vector.ToString();

}
