// Baekjoon17362.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int mod = n % 8;
    if (mod == 0 || mod == 2)
        cout << "2";
    else if (mod == 1)
        cout << "1";
    else if (mod == 3 || mod == 7)
        cout << "3";
    else if (mod == 4 || mod == 6)
        cout << "4";
    else
        cout << "5";
    cout << '\n';

    return 0;
}
