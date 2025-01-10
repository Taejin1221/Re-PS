// Baekjoon16943.cpp
#include <iostream>

#include <string>

using namespace std;

int n, ans = -1, target;
string source;
bool visited[10];

void solve(int curr, int len) {
    if (len == n) {
        if (curr < target)
            ans = max(ans, curr);
    } else {
        for (int i = 0; i < source.size(); i++) {
            if (!visited[i]) {
                if (len == 0 && source[i] == '0')
                    continue;

                visited[i] = true;
                solve(curr * 10 + (source[i] - '0'), len + 1);
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    cin >> source >> target;
    n = source.size();

    solve(0, 0);

    cout << ans << '\n';

    return 0;
}
