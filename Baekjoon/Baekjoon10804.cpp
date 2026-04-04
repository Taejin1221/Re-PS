// Baekjoon10804.cpp
#include <iostream>

using namespace std;

int main(void) {
    int arr[21];
    for (int i = 1; i <= 20; i++)
        arr[i] = i;

    for (int i = 0; i < 10; i++) {
        int left, right;
        cin >> left >> right;

        int temp[21];
        for (int j = 0; j < (right - left + 1); j++) {
            temp[j] = arr[right - j];
        }

        for (int j = 0; j < (right - left + 1); j++)
            arr[left + j] = temp[j];
    }

    for (int i = 1; i <= 20; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
