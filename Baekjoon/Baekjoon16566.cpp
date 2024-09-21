// Baekjoon16566.cpp
#include <iostream>

#include <algorithm>

#define MAX 4'000

using namespace std;

int parents[MAX];

int findRoot(int curr) {
    return (parents[curr] == curr ? curr : parents[curr] = findRoot(parents[curr]));
}

void unionRoots(int a, int b) {
    int aRoot = findRoot(a);
    int bRoot = findRoot(b);

    parents[aRoot] = bRoot;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    int cards[MAX];
    for (int i = 0; i < m; i++) {
        cin >> cards[i];
        parents[i] = i;
    }
    sort(cards, cards + m);

    for (int i = 0; i < k; i++) {
        int target;
        cin >> target;

        int firstIdx = upper_bound(cards, cards + m, target) - cards;

        int findIdx = findRoot(firstIdx);
        cout << cards[findIdx] << '\n';
        if (findIdx + 1 < m)
            unionRoots(findIdx, findIdx + 1);
    }

    for (int i = 0; i < m; i++)
        cout << parents[i] << ' ';
    cout << '\n';

    return 0;
}