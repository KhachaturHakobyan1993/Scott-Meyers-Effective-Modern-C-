#include <iostream>
using namespace std;
using FunctionType = bool(*)(int);
using SortType = bool(*)(int, int);

void display(int array[],
             int size,
             FunctionType check) {
    for(int i = 0; i < size; ++i) {
        int item = array[i];

        bool isSuccess = check(item);

        if(isSuccess) {
            cout<<item<<" ";
        }
    }
    cout<<endl;
}

void sort(int array[],
          int size,
          SortType sort) {

    for(int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1 - i; ++j) {

            if(sort(array[j], array[j+1])) {
                array[j] += array[j + 1];
                array[j + 1] = array[j] - array[j + 1];
                array[j] -= array[j + 1];
            }
        }
    }
}


int main() {
    int array[] = { 200, 122, 44, 33, 22, 22, 11 };

    sort(array, 7, [](int item1, int item2) {
        return item1 > item2;
    });

    display(array, 7, [](int element) {
        return true;
    });

    sort(array, 7, [](int item1, int item2) {
        return item1 < item2;
    });

    FunctionType find = [](int element) {
        return true;
    };

    bool isFound = find(23);

    display(array, 7, find);


    return 0;
}
