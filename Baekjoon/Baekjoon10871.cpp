// Baekjoon10871.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (num < x)
            cout << num << ' ';
    }
    cout << '\n';

    return 0;
}