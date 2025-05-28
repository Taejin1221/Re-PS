// Baekjoon11687.cpp
#include <iostream>

using namespace std;

using ll = long long;

int get0(ll num) {
    int result = 0;
    for (int i = 5; i <= num; i *= 5)
        result += (num / i);

    return result;
}

int main(void) {
    int m;
    cin >> m;

    ll left = 0, right = 400000020;
    while (left + 1 < right) {
        ll mid = (left + right) / 2;
        if (get0(mid) >= m)
            right = mid;
        else
            left = mid;
    }

    cout << (get0(right) == m ? right : -1) << '\n';

    return 0;
}
