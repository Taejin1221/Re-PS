// Baekjoon10775.cpp
#include <iostream>

using namespace std;

int parent[100'001];

int find(int target) {
    return parent[target] = (parent[target] == target ? target : find(parent[target]));
}

void unite(int a, int b) {
    int aRoot = find(a), bRoot = find(b);

    if (aRoot < bRoot)
        parent[bRoot] = aRoot;
    else
        parent[aRoot] = bRoot;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    int ans = 0;
    for (int i = 0; i < m; i++) {
        int plane;
        cin >> plane;

        int root = find(plane);
        if (root != 0) {
            unite(root - 1, root);
            ans++;
        } else
            break;
    }

    cout << ans << '\n';

    return 0;
}
