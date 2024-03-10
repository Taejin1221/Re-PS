// Baekjoon01269.cpp
#include <iostream>

#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    set<int> a;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        a.insert(num);
    }

    int inter = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (a.find(num) != a.end())
            inter++;
    }

    cout << (n + m - 2 * inter) << '\n';

    return 0;
}