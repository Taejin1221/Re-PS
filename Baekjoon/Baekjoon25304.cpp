// Baekjoon25304.cpp
#include <iostream>

using namespace std;

int main(void) {
    int x;
    cin >> x;

    int t;
    cin >> t;

    int sum = 0;
    while (t--) {
        int price, num;
        cin >> price >> num;

        sum += price * num;
    }

    cout << ((sum == x) ? "Yes" : "No") << '\n';

    return 0;
}