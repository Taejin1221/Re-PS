// Baekjoon02455.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans = 0;

    int train = 0;
    for (int i = 0; i < 4; i++) {
        int minus, plus;
        cin >> minus >> plus;

        train -= minus;
        train += plus;

        ans = max(ans, train);
    }

    cout << ans << '\n';

    return 0;
}
