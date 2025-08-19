// Baekjoon02845.cpp
#include <iostream>

using namespace std;

int main(void) {
    int l, p;
    cin >> l >> p;

    int ans = l * p;
    for (int i = 0; i < 5; i++) {
        int news;
        cin >> news;

        cout << (news - ans) << ' ';
    }
    cout << '\n';

    return 0;
}
