// Baekjoon11278.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int n, m;
pii claudes[100];
bool variables[21];

bool isTrue() {
    for (int i = 0; i < m; i++) {
        int first = claudes[i].first, second = claudes[i].second;

        bool x1, x2;
        if (first < 0)
            x1 = !variables[-first];
        else
            x1 = variables[first];

        if (second < 0)
            x2 = !variables[-second];
        else
            x2 = variables[second];

        if (!(x1 | x2))
            return false;
    }

    return true;
}

bool solve(int curr) {
    if (curr > n) {
        return isTrue();
    } else {
        if (solve(curr + 1))
            return true;

        variables[curr] = true;
        if (solve(curr + 1))
            return true;
        variables[curr] = false;
    }

    return false;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> claudes[i].first >> claudes[i].second;

    bool ans = solve(1);

    cout << ans << '\n';
    if (ans) {
        for (int i = 1; i <= n; i++)
            cout << variables[i] << ' ';
        cout << '\n';
    }

    return 0;
}
