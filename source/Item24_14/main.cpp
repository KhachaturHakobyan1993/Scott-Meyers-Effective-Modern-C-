#include <iostream>
#include <chrono>
using namespace std;


void sayHello() {
    cout<<"Hello\n";
}

void song() {
    cout<<"Song\n";
}

void goodGye(string name) {
    cout<<"Good Bye "<<name<<endl;
}

int sum(int value1, int value2) {
    int sum = value1 + value2;

    cout<<value1<<" + "<<value2<<" = "<<sum<<endl;

    return sum;
}

void display(int from, int to) {
    if (from <= to) {
        for(int i = from; i <= to; ++i) {
            cout<<i<<" ";
        }
        cout<<endl;
    } else {
        cout << "Invalid Range\n";
    }
}

void callFunctionWithTime(void(*function)()) {
    auto start = std::chrono::high_resolution_clock::now();
    function();
    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    cout <<"Duration = "<<duration<<endl;
}

int main() {

    callFunctionWithTime( { cout<<""; } );


    return 0;
}
