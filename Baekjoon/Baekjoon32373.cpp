// Baekjoon32373.cpp
#include <iostream>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    bool ans = true;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (ABS(num - i) % k != 0)
            ans = false;
    }

    cout << (ans ? "Yes" : "No") << '\n';

    return 0;
}