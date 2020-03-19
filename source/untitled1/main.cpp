#include <iostream>
#include <future>
using namespace std;

int sum(){
    int result = 10 + 2;

    return result;
}

void say() {
    auto mySum = async(sum);
}


int main() {
    say();


    cout<<"ASQDWQDWQSDW\n";

    return 0;
}
