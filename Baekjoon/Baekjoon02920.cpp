// Baekjoon02920.cpp
#include <iostream>

using namespace std;

int main(void) {
    int arr[8];
    for (int i = 0; i < 8; i++)
        cin >> arr[i];

    bool isAscending = true;
    for (int i = 1; i <= 8; i++)
        if (arr[i - 1] != i)
            isAscending = false;

    bool isDescending = true;
    for (int i = 0; i < 8; i++)
        if (arr[i] != 8 - i)
            isDescending = false;

    if (isAscending)
        cout << "ascending";
    else if (isDescending)
        cout << "descending";
    else
        cout <<  "mixed";
    cout << '\n';

    return 0;
}