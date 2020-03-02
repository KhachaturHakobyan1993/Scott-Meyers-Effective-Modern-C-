#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    Car(int age, int aa, int bb) {

    }
};

class Person {
public:
    int age;
    int height;

    Person(int age, int height) {
        this->age = age;
        this->height = height;
        cout<<"Person init\n";
    }

    void display() {
        cout<<age<<", "<<height<<endl;
    }
};

template <typename T, typename... Ts>
unique_ptr<T> makeX(Ts&&... params) {
    return unique_ptr<T>(new T(forward<Ts>(params)...));
}
template <typename T>
void say(T first) {
     cout<<first<<endl;
}

template <typename T, typename... Ts>
void say(T first, Ts... params) {
    cout<<first<<", ";
    say(params...);
}

int main() {
    //auto initList = ;
    auto spv = std::make_shared<std::vector<int>>({ 10, 20 });

    say("Aramik", "Lilitik", "Koryunik", "AAAAA");

    auto a = makeX<Person>(22, 44);
    auto b = makeX<Car>(55, 44, 55);

   // auto madePointer = make_unique<Person>(23, 44);
//
//    madePointer->display();
//
//
//    cout<<"Hello\n";

    return 0;
}
