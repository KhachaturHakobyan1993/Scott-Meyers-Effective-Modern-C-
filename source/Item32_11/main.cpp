#include <iostream>
using namespace std;

void song() {
    cout<<"Song\n";
}

void sayHello() {
    cout<<"Hello\n";

    auto myLocalFunction = []() {
        cout<<"myLocalFunction1\n";
        cout<<"myLocalFunction2\n";
    };

    myLocalFunction();

    song();
}


int main() {
    sayHello();
    return 0;
}
