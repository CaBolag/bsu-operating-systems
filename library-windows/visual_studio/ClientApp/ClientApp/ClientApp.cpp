#include <iostream>
#include<Vector.h>

int main()
{
    Math::DoubleVector vector1(Math::CreateNumber(1.),Math::ZERO_DNUMBER);
    Math::DoubleVector one_vector = Math::ONE_DVECTOR;
    Math::DoubleVector result_vector = vector1 + one_vector;
    std::cout << "vector1:\n "<<vector1.ToString();
    std::cout << "vector2:\n "<<one_vector.ToString();
    std::cout <<"vector1 + vector2:\n " <<result_vector.ToString();
    
}
