// Baekjoon02738.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, m;
    cin >> n >> m;
    
    int matA[100][100], matB[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
             cin >> matA[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
             cin >> matB[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << matA[i][j] + matB[i][j] << ' ';
        cout << '\n';
    }

    return 0;
}