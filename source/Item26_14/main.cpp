#include <iostream>
#include <string>
using namespace std;

string nameFromIdx(int index) {

    return "Kikos";
};

class Person {
private:
    string name;
public:
    template <typename T>
    explicit Person(T&& n): name(forward<T>(n)) {
        cout<<"Person Template = "<<name<<endl;
    }

Person() {
    cout<<"Person\n";
}

    Person(const Person& rhs) {
        name = rhs.name;
        cout<<"Person Copy = "<<name<<endl;
    }

    explicit Person(int index): name(nameFromIdx(index)) {
        cout << "Person Integer = "<<name<<endl;
    }
};


class SpecialPerson: public Person {
public:
    SpecialPerson() {
        cout<<"SpecialPerson\n";
    }

    SpecialPerson(const SpecialPerson& rhs)
            : Person(rhs) {
        cout<<"SpecialPerson Copy\n";
    }
};

int main() {

    SpecialPerson aramik;
    Person v;

    cout<<"ddddd\n";

    auto aaa(aramik);



    return 0;
}
