// Baekjoon02562.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int firstVal;
    cin >> firstVal;

    pii ans = { firstVal, 1 };
    for (int i = 2; i <= 9; i++) {
        int temp;
        cin >> temp;

        if (ans.first < temp)
            ans = { temp, i };
    }

    cout << ans.first << '\n';
    cout << ans.second << '\n';

    return 0;
}