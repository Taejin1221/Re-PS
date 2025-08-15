// Baekjoon01091.cpp
#include <iostream>

#include <vector>

using namespace std;

int s[48];
bool visited[48];

int getGCD(int a, int b) {
    return (b ? getGCD(b, a % b) : a);
}

int dfs(int curr, int time) {
    int next = s[curr];
    if (!visited[next]) {
        visited[next] = true;

        return dfs(next, time + 1);
    }

    return time;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int p[48];
    for (int i = 0; i < n; i++)
        cin >> p[i];

    int card[48];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        card[i] = i;
    }

    vector<int> cycles;
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            cycles.push_back(dfs(i, 1));
    }

    int lcm = cycles[0], gcd = cycles[0];
    for (int i = 1; i < cycles.size(); i++) {
        lcm *= cycles[i];
        gcd = (gcd > cycles[i]) ? getGCD(gcd, cycles[i]) : getGCD(cycles[i], gcd);
    }

    if (cycles.size() > 1)
        lcm /= gcd;

    int ans = -1, newCards[48];
    for (int i = 0; i < lcm; i++) {
        bool isAnswer = true;
        for (int i = 0; i < n; i++) {
            if (p[card[i]] != i % 3) {
                isAnswer = false;
                break;
            }
        }

        if (isAnswer) {
            ans = i;
            break;
        }

        for (int i = 0; i < n; i++)
            newCards[s[i]] = card[i];

        for (int i = 0; i < n; i++)
            card[i] = newCards[i];
    }

    cout << ans << '\n';

    return 0;
}
