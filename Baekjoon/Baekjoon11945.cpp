// Baekjoon11945.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;

    string ing[10];
    for (int i = 0; i < n; i++)
        cin >> ing[i];

    for (int i = 0; i < n; i++) {
        for (int j = m - 1; j >= 0; j--)
            cout << ing[i][j];
        cout << '\n';
    }

    return 0;
}
