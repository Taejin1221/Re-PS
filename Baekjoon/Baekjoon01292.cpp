// Baekjoon01292.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;

    int time = 1, ans = 0;
    for (int i = 1; i < 1'000; i++) {
        for (int j = 0; j < i; j++) {
            if (a <= time && time <= b)
                ans += i;
            time++;
        }
    }

    cout << ans << '\n';

    return 0;
}