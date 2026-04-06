// Baekjoon02460.cpp
#include <iostream>

using namespace std;

int main(void) {
    int ans = 0, train = 0;
    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;

        train -= a;
        train += b;

        ans = max(ans, train);
    }

    cout << ans << '\n';

    return 0;
}
