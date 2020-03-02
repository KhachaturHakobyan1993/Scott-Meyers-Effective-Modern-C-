#include <iostream>
#include <vector>

std::vector<bool> featuresBooleans() {
      std::vector<bool> a ;
      a.insert(a.begin(), true);
    a.insert(a.begin(), true);
    a.insert(a.begin(), false);
    a.insert(a.begin(), true);
    a.insert(a.begin(), true);
    a.insert(a.begin(), true);
    a.insert(a.begin(), false);
    a.insert(a.begin(), true);

    return a;
}

void sayHelloBoolean(bool value) {
    std::cout<<"Boolean Hello "<<value<<std::endl;
}



int main() {

    auto boolHighPriority = featuresBooleans()[5];

    std::cout << "Helllo\n";


    for (int i = 0; i > -1; ++i) {
        bool aa = true;
        for (int i = 0; i < 100 ; ++i) {
            bool aa = true;
        }
        for (int i = 0; i < 100 ; ++i) {
            bool aa = true;
        }

            sayHelloBoolean(boolHighPriority);
    }


    return 0;
}
