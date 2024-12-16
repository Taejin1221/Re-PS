// Baekjoon05217.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        cout << "Pairs for " << n << ": ";

        int count = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || j < i)
                    continue;

                if (i + j == n) {
                    if (count)
                        cout << ", ";
                    cout << i << " " << j;
                    count++;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}