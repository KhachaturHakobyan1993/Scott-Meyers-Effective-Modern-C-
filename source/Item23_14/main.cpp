#include <iostream>
#include <chrono>
using namespace std;

class Widget {
public:
    string name;
};


void process(const Widget& lvalArg) {
    cout<<"AAAAAA "<<lvalArg.name<<endl;
}
void process(Widget&& rvalArg) {
    cout<<"BBBBBB "<<rvalArg.name<<endl;
}

template<typename T>
void logAndProcess(T&& param) {
    cout<<"Calling 'process' ";
   // process(std::forward<T>(param));
    process(forward<T>(param));
}

template<typename T>
decltype(auto) moveX(T&& param) {
    using ReturnType = remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

//template <typename T>
void say(int&& value) {

}

int main() {
    Widget widget;
    widget.name = "Ann";

    logAndProcess(move(widget));

    return 0;
}
