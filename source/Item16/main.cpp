#include <iostream>
#include <vector>
#include <thread>

class Polynomial {
public:
    using RootsType = std::vector<double>;

    RootsType roots() const {
        std::lock_guard<std::mutex> g(m);

        if(!rootsAreValid) {
            rootsAreValid = true;

            for(int i = 0; i < 1000; ++i) {
                std::cout<<i<<" ";
            }
            std::cout<<"\r"<<std::endl;

            rootValues = { 999, 33 };

        }

        return rootValues;
    };

    void sayHello() {
        ++count;
    }

//    mutable std::atomic<unsigned > count { 0 };
    int count = 0;


private:
    mutable std::mutex m;
    mutable bool rootsAreValid { false };
    mutable RootsType rootValues { 888 };
};

void callRootFuntion(Polynomial& polynomial) {
    std::cout<<"Thread Id = "<<std::this_thread::get_id()<<std::endl;

    auto roots = polynomial.roots();

    std::cout<<"\nRoots first elements is "<<*roots.begin()<<"\n"<<std::endl;
    std::cout<<"\r"<<std::endl;
}

void callSayFunction(Polynomial& polynomial) {
    polynomial.sayHello();
}

int main() {
    Polynomial p;

    // Task 1

//    std::thread first_thread(callRootFuntion, std::ref(p));
//
//    std::thread second_thread(callRootFuntion, std::ref(p));
////
//    std::thread third_thread(callRootFuntion, std::ref(p));


    // Task 2


    const int size = 10000;

    std::thread threads[size];

    for(int i = 0; i < size; ++i) {
        threads[i] = std::thread(callSayFunction, std::ref(p));
    }


    for(int i = 0; i < size; ++i) {
        threads[i].join();
    }

    std::cout<<"----------End----------"<<std::endl;


    std::cout<<std::endl<<p.count<<std::endl;



//    std::thread first_thread(callSayFunction, std::ref(p));
//    std::thread second_thread(callSayFunction, std::ref(p));
//    std::thread third_thread(callSayFunction, std::ref(p));
//    std::thread fourth_thread(callSayFunction, std::ref(p));
//    first_thread.join();
//    second_thread.join();
//    third_thread.join();
//    fourth_thread.join();



//



    return 0;
}
