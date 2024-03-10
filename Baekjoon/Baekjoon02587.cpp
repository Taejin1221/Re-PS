// Baekjoon02587.cpp
#include <iostream>

using namespace std;

int main(void) {
    int arr[5], sum = 0;
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum / 5 << '\n';
    for (int i = 5; i >= 0; i--) {
        for (int j = 0; j < i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << arr[2] << '\n';

    return 0;
}