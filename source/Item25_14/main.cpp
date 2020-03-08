#include <iostream>
using namespace std;

class Widget {
public:
    Widget() {
        cout<<"Widget\n";
    }

    Widget(const Widget& other) {
        cout<<"Copy Widget\n";
    }

    Widget(Widget&& other) {
        cout<<"Move Widget\n";
    }

    ~Widget() {
        cout<<"~Widget\n";
    }

    void displayAddress() {
        cout<<"Address = "<<this<<endl;
    }
};

Widget makeWidget() {
    Widget widgetLocal;

    widgetLocal.displayAddress();

    return widgetLocal;
}

Widget updateWidget(Widget localWidget) {
    localWidget.displayAddress();

    return move(localWidget);
}


int main() {
//
//    auto widget = makeWidget();
//
//    widget.displayAddress();

     auto widget = Widget();
     widget.displayAddress();

     auto updatedWidget = updateWidget(widget);
     updatedWidget.displayAddress();

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
