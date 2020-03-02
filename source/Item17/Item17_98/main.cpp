#include <iostream>
using namespace std;

class Widget {
public:
    Widget();

    ~Widget();
};

void sayHello(Widget widget) {
    cout<<"Address Of Wiget = "<<&widget<<endl;
}


int main() {
    Widget widget;

    Widget w2 = move(widget);



    return 0;
}
