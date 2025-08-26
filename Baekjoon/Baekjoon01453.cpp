// Baekjoon01453.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int ans = 0;
    bool visited[101] = { false, };
    for (int i = 0; i < n; i++) {
        int seat;
        cin >> seat;

        if (!visited[seat])
            visited[seat] = true;
        else
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
