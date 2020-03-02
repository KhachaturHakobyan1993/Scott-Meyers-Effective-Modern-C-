#include <iostream>
using namespace std;


class Investment {
public:
    string name = "Investment";

    Investment() {
        std::cout<<"InvestmentXXXXXXXX\n";
    }

   virtual void sayHello() {
        std::cout<<"Investment Hello.\n";
    }

    virtual ~Investment() {
        std::cout<<"Investment ~Destrictor.\n";
    }
};

class Stock: public Investment {
public:
    int age = 22;

    Stock() {
        std::cout<<"StockXXXXXXXX\n";
    }

    virtual void sayHello() override {
        std::cout<<"Stock Hello.\n";
    }

    ~Stock() {
        std::cout<<"Stock ~Destrictor.\n";
    }
};

class Bond: public Investment {
public:
    double value = 23.0;

    void sayHello() override {
        std::cout<<"Bond Hello.\n";
    }

    ~Bond() {
        std::cout<<"Bond ~Destrictor.\n";
    }
};

class RealEstate: public Investment {
public:
    char flag = 'F';

    void sayHello() override {
        std::cout<<"RealEstate Hello.\n";
    }

    ~RealEstate() {
        std::cout<<"RealEstate ~Destrictor.\n";
    }
};


Stock makeInvestment(int value) {

   // if (value == 11) {
        Stock stock;

        return stock;
//    } else if(value == 22 ) {
//        Bond bond;
//
//        return bond;
//    } else {
//        RealEstate realEstate;
//
//        return realEstate;
//    }
}

void say() {

    Investment pointer = makeInvestment(22);


    pointer.sayHello();
}

int main() {

    say();

    std::cout<<"End_____________\n";

    return 0;
}
