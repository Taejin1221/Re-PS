// Baekjoon01835.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);

    int ans[1'000];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            q.push(q.front());
            q.pop();
        }

        ans[q.front()] = i;
        q.pop();
    }

    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
