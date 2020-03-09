#include <iostream>
#include <string>
using namespace std;

string nameFromIdx(int index) {
    return "Kikos";
};

class A {
public:
};


class Person {
private:
    string name;
public:
    template<
            typename T,
            typename = std::enable_if_t<
                    !std::is_base_of<Person, std::decay_t<T>>::value
                    &&
                    !std::is_integral<std::remove_reference_t<T>>::value
            >
    >
    explicit Person(T&& n): name(forward<T>(n)) {
        cout<<"Person Template = "<<name<<endl;

        static_assert(
                std::is_constructible<std::string, T>::value, "Parameter n can't be used to construct a std::string"
        );
    }

    Person() {

    }

    Person(const Person& rhs) {
        name = rhs.name;
        cout<<"Person Copy = "<<name<<endl;
    }

    explicit Person(int index): name(nameFromIdx(index)) {
        cout << "Person Integer = "<<name<<endl;
    }

    void display() {
        cout<<this->name<<endl;
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

//    SpecialPerson aramik;
//    Person v;
//
//    cout<<"ddddd\n";
//
//    auto aaa(aramik);
//

//    Person lilit("Lilit");
//    Person karen(777);

    A aaaa;

    Person vahag(aaaa);

    //vahag.display();





    return 0;
}