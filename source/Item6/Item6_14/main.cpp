#include <iostream>
#include <vector>

std::vector<bool> featuresBooleans() {
    return  { true, false, false, true, true, true, true, true };
}

void sayHelloBoolean(bool value) {
    std::cout<<"Boolean Hello "<<value<<std::endl;
}


std::vector<int> featuresIntegers() {
    return  { 11, 22, 33, 44, 55, 66, 77 };
}

void sayHelloInteger(int value) {
    std::cout<<"Integer Hello "<<value<<std::endl;
}

int main() {

    auto boolHighPriority = featuresBooleans()[1];

    std::cout << "Helllo\n";


    for (int i = 0; i > -1; ++i) {
    sayHelloBoolean(boolHighPriority);

    }


    return 0;
}
