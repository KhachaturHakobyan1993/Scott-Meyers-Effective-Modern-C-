#include <iostream>
using namespace std;

template<typename T>
typename remove_reference<T>::type&&
moveX(T&& param) {
    using ReturnType = typename remove_reference<T>::type&&;

    return static_cast<ReturnType>(param);
}

template <typename T>
void say(T&& a) {
    a = 234;
}

template<typename T>
decltype(auto) move(T&& param) {
    using ReturnType = typename remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

int main() {

    auto value = moveX(133);
    int aaa = 23;

    say(23);
    say(aaa);
    cout<<aaa<<endl;


    auto ccc = moveX(aaa);



    return 0;
}
