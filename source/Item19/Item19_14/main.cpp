#include <iostream>
using namespace std;

class Person {
public:
    string name = string();
    weak_ptr<Person> oldFriend;


    Person() {
        cout<<"Person Constructor: "<<endl;
    }

    Person(string name) {
        this->name = name;
        cout<<"Person Constructor: "<<name<<endl;
    }

    ~Person() {
        cout<<"Person Deconstructor: "<<name<<endl;
    }
};

class Office {
public:
    Person aramik{"Aramik"};
    Person lilitik{"Lilitik"};
    Person koryunik{"Koryunik"};

    Office() {
        cout<<"Office Constructor\n";
    }

    ~Office() {
        cout<<"Office Deconstructor\n";
    }
};



int main() {
    shared_ptr<Person> aramik(new Person);
    shared_ptr<Person> lilitik(new Person);
    shared_ptr<Person> koryunik(new Person);

    aramik->name = "Aramik";
    lilitik->name = "Lilitik";
    koryunik->name = "Koryunik";

    aramik->oldFriend = lilitik;
    lilitik->oldFriend = aramik;

    cout<<aramik.use_count()<<endl;
    cout<<lilitik.use_count()<<endl;
    cout<<koryunik.use_count()<<endl;

    cout<<"----------End----------\n";
    return 0;
}