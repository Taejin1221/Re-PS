// Baekjoon10811.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    int buckets[101], temp[101];
    for (int i = 1; i <= n; i++)
        buckets[i] = i;

    for (int t = 0; t < m; t++) {
        int start, end;
        cin >> start >> end;

        for (int i = start; i <= end; i++)
            temp[i] = buckets[i];
        for (int i = start, j = end; i <= end; i++, j--)
            buckets[i] = temp[j];
    }

    for (int i = 1; i <= n; i++)
        cout << buckets[i] << ' ';
    cout << '\n';

    return 0;
}