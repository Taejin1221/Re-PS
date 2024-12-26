// Baekjoon22966.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    pair<string, int> ans = { "", 5 };
    for (int i = 0; i < n; i++) {
        string name;
        int diff;
        cin >> name >> diff;

        if (diff < ans.second)
            ans = { name, diff };
    }

    cout << ans.first << '\n';

    return 0;
}
