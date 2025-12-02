// Baekjoon34750.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    int n;
    cin >> n;

    int give;
    if (n >= 1'000'000)
        give = n * 20;
    else if (n >= 500'000)
        give = n * 15;
    else if (n >= 100'000)
        give = n * 10;
    else
        give = n * 5;
    give /= 100;

    cout << give << ' ' << (n - give) << '\n';

    return 0;
}
