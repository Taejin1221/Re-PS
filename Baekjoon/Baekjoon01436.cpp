// Baekjoon01436.cpp
#include <iostream>

using namespace std;

bool isEndNumber(int n) {
    char number[10] = { 0, };

    int idx = 0;
    while (n) {
        number[idx++] = (n % 10) + '0';
        n /= 10;
    }

    for (int i = 0; i <= idx - 3; i++)
        if (number[i] == '6' && number[i + 1] == '6' && number[i + 2] == '6')
            return true;

    return false;
}

int main(void) {
    int target;
    cin >> target;

    int n = 1, ans;
    for (int i = 666; i <= 10'000'000; i++) {
        if (isEndNumber(i)) {
            if (n == target) {
                ans = i;
                break;
            } else
                n++;
        }
    }

    cout << ans << '\n';

    return 0;
}