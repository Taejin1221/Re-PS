// Baekjoon02577.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    cin >> a >> b >> c;

    int mul = a * b * c;

    int time[10] = { 0, };
    while (mul) {
        time[mul % 10]++;

        mul /= 10;
    }

    for (int i = 0; i < 10; i++)
        cout << time[i] << '\n';

    return 0;
}