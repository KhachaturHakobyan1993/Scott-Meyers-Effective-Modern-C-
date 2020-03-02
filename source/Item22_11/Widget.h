//
// Created by Khachatur Hakobyan on 3/2/20.
//

#ifndef ITEM22_11_WIDGET_H
#define ITEM22_11_WIDGET_H


#include <memory>

class Widget {
public:
    Widget();
    //~Widget();
    struct Impl;
    std::shared_ptr<Impl> pImpl;
private:



};


#endif //ITEM22_11_WIDGET_H
