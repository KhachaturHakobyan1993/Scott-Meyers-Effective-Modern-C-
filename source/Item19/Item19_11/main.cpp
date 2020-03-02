#include <iostream>
using namespace std;

class Person {
public:
    string name = "Aram";

    Person() {
        cout<<"Person Constructor\n";
    }

    ~Person() {
        cout<<"Person Deconstructor "<<this<<endl;
    }
};


void say() {


    Person* personPoint = new Person;

    shared_ptr<Person> uuu(personPoint);

    shared_ptr<Person> uuu2(move(uuu));

    cout<<uuu.use_count()<<endl;

    cout<<uuu2.use_count()<<endl;


    cout<<"End of say function\n";
}


void log(Person* p) {
    cout<<"Call khachatur\n";
    delete p;
}

int main() {

    Person* personPointer = new Person;

    unique_ptr<Person, void(*)(Person*)> p1(personPointer, log);

    shared_ptr<Person> p3(personPointer, log);

    return 0;
}
