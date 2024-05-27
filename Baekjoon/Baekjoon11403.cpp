// Baekjoon11403.cpp
#include <iostream>

#include <vector>

using namespace std;

using vii = vector<vector<int>>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    vii adjMatrix(n, vector<int> (n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> adjMatrix[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][k] && adjMatrix[k][j])
                    adjMatrix[i][j] = 1;
            }
        }
    }

    for (vector<int>& row : adjMatrix) {
        for (int& element : row)
            cout << element << ' ';
        cout << '\n';
    }

    return 0;
}