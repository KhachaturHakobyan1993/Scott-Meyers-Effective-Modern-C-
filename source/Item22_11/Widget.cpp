//
// Created by Khachatur Hakobyan on 3/2/20.
//

#include "Widget.h"
#include <iostream>

#include <string>
#include <vector>
#include "Gadget.h"
using namespace std;

struct Widget::Impl {
public:
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;

    Impl() {
        std::cout<<"Imple\n";
    }

    ~Impl() {
        std::cout<<"~Imple\n";
    }
};


Widget::Widget() : pImpl(std::make_shared<Impl>()) {
    std::cout<<"Widget\n";
}

//Widget::~Widget() {
//    std::cout<<"~Widget\n";
//}