// Baekjoon30019.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    int classRoom[200'001] = { 0, };
    for (int i = 0; i < m; i++) {
        int k, s, e;
        cin >> k >> s >> e;

        if (classRoom[k] <= s) {
            classRoom[k] = e;
            cout << "YES";
        } else
            cout << "NO";
        cout << '\n';
    }

    return 0;
}