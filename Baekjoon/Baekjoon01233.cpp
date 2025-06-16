// Baekjoon01233.cpp
#include <iostream>

using namespace std;

int main(void) {
    int s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int ans = 0;
    int sums[100] = { 0, };
    for (int i = 1; i <= s1; i++) {
        for (int j = 1; j <= s2; j++) {
            for (int k = 1; k <= s3; k++) {
                int sum = i + j + k;
                sums[sum]++;

                ans = max(ans, sums[sum]);
            }
        }
    }

    for (int i = 1; i < 100; i++) {
        if (sums[i] == ans) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}
