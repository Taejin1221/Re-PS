// Baekjoon10989.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int count[10'001] = { 0, };
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        count[temp]++;
    }

    for (int i = 1; i <= 10'000; i++)
        while (count[i]--)
            cout << i << '\n';

    return 0;
}