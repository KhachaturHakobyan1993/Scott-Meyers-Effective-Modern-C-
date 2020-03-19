#include <iostream>
#include <thread>
#include <vector>

class ThreadRAII {
public:
    enum class DtorAction { join, detach };

    ThreadRAII(std::thread&& t, DtorAction a)
            : action(a), t(std::move(t)) { }

    ~ThreadRAII() {
        if (t.joinable()) {
            if (action == DtorAction::join) {
                t.join();
            } else {
                t.detach();
            }
        }
    }

    std::thread& get() { return t; }
private:
    DtorAction action;
    std::thread t;
};

bool conditionsAreSatisfied() {
    return false;
}

void performComputation(std::vector<int> goodVals) {
    for(auto i = goodVals.begin(); i != goodVals.end(); i++) {
        std::cout<<*i<<" ";
    }
    std::cout<<std::endl;
}

bool doWork(std::function<bool(int)> filter,
            int maxVal = 10000) {
    std::vector<int> goodVals;

    ThreadRAII t(
            std::thread([&filter, maxVal, &goodVals] {

                for (auto i = 0; i <= maxVal; ++i) {
                    if (filter(i))
                        goodVals.push_back(i);
                }
            }),
            ThreadRAII::DtorAction::join
    );

    auto nh = t.get().native_handle();

    if (conditionsAreSatisfied()) {
        t.get().join();
        performComputation(goodVals);
        return true;
    }

    return false;
}



int main() {
    doWork([](int value){
        return value > 1000;
    }, 1500);

    return 0;
}
