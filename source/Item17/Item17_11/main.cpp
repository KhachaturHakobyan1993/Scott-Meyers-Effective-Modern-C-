#include <iostream>
using namespace std;

class Widget {
public:
    Widget();
};

void sayHello(Widget widget) {
    cout<<"Address Of Wiget = "<<&widget<<endl;
}


int main() {
    Widget widget;

    Widget w2 = move(widget);

    Widget w3;
    w3 = move(w2);



    return 0;
}
