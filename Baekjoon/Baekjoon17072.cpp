// Baekjoon17072.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int r, g, b;
            cin >> r >> g >> b;

            int color = 2126 * r + 7152 * g + 722 * b;
            if (color < 510'000)
                cout << '#';
            else if (color < 1'020'000)
                cout << 'o';
            else if (color < 1'530'000)
                cout << '+';
            else if (color < 2'040'000)
                cout << '-';
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}