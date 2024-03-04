// Baekjoon02563.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    bool isBlack[100][100] = { { false, }, };
    while (t--) {
        int x, y;
        cin >> x >> y;

        for (int i = 0; i < 10; i++)
            for (int j = 0; j < 10; j++)
                isBlack[x + i][y + j] = true;
    }

    int ans = 0;
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            ans += (int)isBlack[i][j];

    cout << ans << '\n';

    return 0;
}