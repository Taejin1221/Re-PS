// Baekjoon20113.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int vote[101] = { 0, };
    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;

        vote[v]++;
    }

    bool isSkipped = false;
    pair<int, int> ans = { 1, vote[1] };
    for (int i = 2; i <= n; i++) {
        if (ans.second < vote[i]){
            ans = { i, vote[i] };
            isSkipped = false;
        } else if (ans.second == vote[i])
            isSkipped = true;
    }

    if (isSkipped)
        cout << "skipped";
    else
        cout << ans.first;
    cout << '\n';

    return 0;
}