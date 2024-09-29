// Baekjoon32372.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

void sameAsX(pii ans[], int x) {
    ans[0].first = x;
    ans[1].first = x;
}

void biggerThanX(pii ans[], int x) {
    ans[0].first = max(ans[0].first, x + 1);
}

void smallerThanX(pii ans[], int x) {
    ans[1].first = min(ans[1].first, x - 1);
}

void sameAsY(pii ans[], int y) {
    ans[0].second = y;
    ans[1].second = y;
}

void biggerThanY(pii ans[], int y) {
    ans[0].second = max(ans[0].second, y + 1);
}

void smallerThanY(pii ans[], int y) {
    ans[1].second = min(ans[1].second, y - 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    pii ans[2] = { { 1, 1 }, { n, n } };
    for (int i = 0; i < m; i++) {
        int row, col, num;
        cin >> row >> col >> num;

        if (num == 1) {
            smallerThanX(ans, row);
            sameAsY(ans, col);
        } else if (num == 2) {
            smallerThanX(ans, row);
            biggerThanY(ans, col);
        } else if (num == 3) {
            sameAsX(ans, row);
            biggerThanY(ans, col);
        } else if (num == 4) {
            biggerThanX(ans, row);
            biggerThanY(ans, col);
        } else if (num == 5) {
            biggerThanX(ans, row);
            sameAsY(ans, col);
        } else if (num == 6) {
            biggerThanX(ans, row);
            smallerThanY(ans, col);
        } else if (num == 7) {
            sameAsX(ans, row);
            smallerThanY(ans, col);
        } else {
            smallerThanX(ans, row);
            smallerThanY(ans, col);
        }
    }

    cout << ans[0].first << ' ' << ans[1].second << '\n';

    return 0;
}