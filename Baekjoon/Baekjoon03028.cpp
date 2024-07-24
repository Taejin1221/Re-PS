// Baekjoon03028.cpp
#include <iostream>

#include <string>

using namespace std;

void swap(int& a, int & b) {
    int temp = a;
    a = b;
    b = temp;
}

int main(void) {
    string order;
    cin >> order;

    int cups[3] = { 1, 2, 3 };
    for (char& c : order) {
        if (c == 'A')
            swap(cups[0], cups[1]);
        else if (c == 'B')
            swap(cups[1], cups[2]);
        else
            swap(cups[0], cups[2]);
    }

    if (cups[0] == 1)
        cout << 1;
    else if (cups[1] == 1)
        cout << 2;
    else
        cout << 3;
    cout << '\n';

    return 0;
}