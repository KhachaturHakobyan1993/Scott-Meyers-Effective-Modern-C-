#include <iostream>
using namespace std;


class Investment {
public:

    Investment() {
        std::cout<<"InvestmentXXXXXXXX\n";
    }

    Investment(Investment& a) {
        std::cout<<"Investment Copy\n";
    }

    Investment(Investment&& a) {
        std::cout<<"Investment Move\n";
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

    Stock() {
        std::cout<<"StockXXXXXXXX\n";
    }

    Stock(Stock& a) {
        std::cout<<"Stock Copy\n";
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

    Bond() {
        std::cout<<"BondXXXXXXXX\n";
    }


    virtual void sayHello() override {
        std::cout<<"Bond Hello.\n";
    }

    ~Bond() {
        std::cout<<"Bond ~Destrictor.\n";
    }
};


unique_ptr<Investment []> makeInvestment(int value) {
    Investment* array = new Stock[2];

    unique_ptr<Investment []> pointer(array);
    return pointer;

//    if(value == 11) {
//        Investment* array = new Stock[2];
//
//        pointer.reset(array);
//    } else if(value == 22) {
//        Investment* array = new Bond[2];
//
//        pointer.reset(array);
//    } else {
//        Investment* array = new RealEstate[2];
//
//        pointer.reset(array);
//    }
//
//    return pointer;
}

void say() {
    unique_ptr<Investment []> pointer = makeInvestment(11);
   pointer[0].sayHello();
   pointer[1].sayHello();

   // pointer.release();
}

int main() {

    say();

    std::cout<<"End_____________\n";

    return 0;
}

