// Baekjoon04892.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int time = 1;
    while (n != 0) {
        int n1 = 3 * n;
        int n2 = (n1 % 2 == 0) ? n1 / 2 : (n1 + 1) / 2;
        int n3 = 3 * n2;
        int n4 = n3 / 9;

        cout << time << ". " << (n1 % 2 == 0 ? "even " : "odd ") << n4 << '\n';

        time++;
        cin >> n;
    }

    return 0;
}
