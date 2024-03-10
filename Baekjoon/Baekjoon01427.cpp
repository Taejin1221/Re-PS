// Baekjoon01427.cpp
#include <iostream>

using namespace std;

int main(void) {
    char arr[11] = { 0, };
    cin >> arr;

    int len = 0;
    while (arr[len])
        len++;

    for (int i = len; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << arr << '\n';

    return 0;
}