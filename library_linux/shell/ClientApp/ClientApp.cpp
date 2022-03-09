#include <iostream>
#include <Vector.h>

int main()
{
    Math::Vector vector1(Math::CreateNumber(1.),Math::ZERO_NUMBER);
    Math::Vector one_vector = Math::ONE_VECTOR;
    Math::Vector result_vector = vector1 + one_vector;
    std::cout << "vector1:\n "<<vector1.ToString();
    std::cout << "vector2:\n "<<one_vector.ToString();
    std::cout <<"vector1 + vector2:\n " <<result_vector.ToString();

    std::string result_1_0;
    TransformToPolarVector(1.,0,result_1_0);
    std::cout<<"(1,0) vector in polar coordinates: "<<result_1_0;

}
