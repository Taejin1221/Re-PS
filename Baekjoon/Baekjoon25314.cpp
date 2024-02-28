// Baekjoon25314.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    while (n) {
        cout << "long ";

        n -= 4;
    }
    cout << "int\n";

    return 0;
}