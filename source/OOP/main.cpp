#include <iostream>
#include <list>
using namespace std;
// Incapsulation

const double pi = 3.14;

class Person {
    struct DetailsUnion {
        double height;
        double weight;

        DetailsUnion() {

        }

        DetailsUnion(double height, double weight) {
            this->height = height;
            this->weight = weight;
        }
    };
private:
    int age;
public:
    string name;
    DetailsUnion details;
    //int age;

    Person() {

    }

    Person(string name, int age) {
        this->name = name;
        setAge(age);
    }

    Person(string name, int age, double height, double weight) {
        this->name = name;
        setAge(age);
        this->details = DetailsUnion(height, weight);
    }

    void setAge(int age) {
        if(age <= 0 || age >= 120) {
            cout<<"Error: Invalid Age = "<<age<<". Age range should be 0...120.\n";
        } else {
            this->age = age;
        }
    }

    int getAge() {
        return this->age;
    }

    void displayInfo() {
        cout<<name<<", "<<age<<endl;
    }

    virtual void run() {
        cout<<"Person Run\n";
    }
};

class Student: public Person {
public:
    void run() {
        cout<<"Student Run\n";
    }
};

void displayList(list<int> list) {
    for(auto iterator = list.begin(); iterator != list.end(); iterator++) {
        cout<<*iterator<<" ";
    }
    cout<<endl;
}

int sum(int value1, int valu2) {
    return value1 + valu2;
}

double sum(double value1, double valu2) {
    return value1 + valu2;
}


int main() {
    // Without OOP.
    double radius = 10;
    double area = radius * pi;

    // pi = 23; error, because pi is incapsulated

    cout<<area<<endl;

    // With OOP.

    Person ann;
    ann.name = "Ann";
//    ann.age = 22; // OK.
//    ann.age = 2222; // Logical error,but code will compile. Not OK.
//    ann.age = 0;
//    ann.age = -123;

    // Than age is not incapsulated.
    // To incapsualte age to change age to const is not best way.
    // Because it is logical error.

    // To incapsulate to add private keyword.
    // That age can not be changed on direct way, only undirect way.
    // And it give us chance to validate age property.

    // To set and get age we must use setter and getter functions.

    ann.setAge(22);
    ann.setAge(2222);
    ann.setAge(0);
    ann.setAge(-123);

    Person karen("Karen", 22);
    karen.displayInfo();

    Person john("John", -222);
    john.displayInfo();

    Person aram = Person("Aram", 33, 175.4, 88.8);
    cout<<aram.details.height<<endl;
    cout<<aram.details.weight<<endl;

    //DetailsUnion details = DetailsUnion();// It is not neccessary

    list<int> array = { 22, 33, 44 , 2, 4, 3, 9, 8, 7, 6, 33, 15, 14 };

    displayList(array);

    array.sort();

    displayList(array);

    int sum1 = sum(11, 22);
    double sum2 = sum(11.0, 22.123);

    cout<<sum1<<", "<<sum2<<endl;

    Person alik;
    Student jivan;
    alik.run();
    jivan.run();

    Person *pointerPerson;

    pointerPerson = &alik;
    pointerPerson->run();
    pointerPerson = &jivan;
    pointerPerson->run();

    return 0;
}
