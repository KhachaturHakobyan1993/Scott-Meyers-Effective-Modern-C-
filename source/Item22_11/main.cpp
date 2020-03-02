#include <iostream>
#include "Widget.h"

int main() {
    std::cout << "Hello, World!" << std::endl;


    std::shared_ptr<Widget> p1(new Widget);
    std::cout<<p1.use_count()<<std::endl;

    std::shared_ptr<Widget> p2(p1);
    std::cout<<p1.use_count()<<std::endl;
    std::cout<<p2.use_count()<<std::endl;


    return 0;
}
