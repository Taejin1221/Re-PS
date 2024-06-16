// Baekjoon20436.cpp
#include <iostream>

#include <string>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;

const string leftHand = "qwertasdfgzxcv";

int getHand(char c) {
    for (char l : leftHand)
        if (l == c)
            return 0;

    return 1;
}

int main(void) {
    const string keyboard[3] = {
        "qwertyuiop",
        "asdfghjkl",
        "zxcvbnm"
    };

    pii position[128];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < keyboard[i].size(); j++)
            position[keyboard[i][j]] = { i, j };

    char l, r;
    cin >> l >> r;
    pii currPosition[2] = { position[l], position[r] };

    string str;
    cin >> str;

    int ans = 0;
    for (char& c : str) {
        pii& currPos = currPosition[getHand(c)];
        ans += ABS(currPos.first - position[c].first) + ABS(currPos.second - position[c].second);
        ans++;

        currPos = position[c];
    }

    cout << ans << '\n';

    return 0;
}