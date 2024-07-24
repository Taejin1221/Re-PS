// Baekjoon12851.cpp
#include <iostream>

#include <queue>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n, k;
    cin >> n >> k;

    queue<pii> q;
    int visited[200'001];
    fill(visited, visited + 200'001, 0x3f3f3f3f);
    
    q.push({ n, 0 });
    visited[n] = 0;

    pii ans = { 0, 0 };
    while (!q.empty()) {
        pii curr = q.front(); q.pop();

        if (curr.first == k) {
            if (ans.second == 0)
                ans = { curr.second, 1 };
            else {
                if (ans.first == curr.second)
                    ans.second++;
                else
                    break;
            }
        }

        if (ans.second == 0) {
            int newPos = curr.first + 1, nextSecond = curr.second + 1;
            if (newPos <= 200'000 && visited[newPos] >= nextSecond) {
                visited[newPos] = nextSecond;
                q.push({ newPos, nextSecond });
            }

            newPos = curr.first - 1;
            if (newPos >= 0 && visited[newPos] >= nextSecond) {
                visited[newPos] = nextSecond;
                q.push({ newPos, nextSecond });
            }

            newPos = curr.first * 2;
            if (newPos <= 200'000 && visited[newPos] >= nextSecond) {
                visited[newPos] = nextSecond;
                q.push({ newPos, nextSecond });
            }
        }
    }

    cout << ans.first << '\n';
    cout << ans.second << '\n';

    return 0;
}