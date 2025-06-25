// Baekjoon23841.cpp
#include <iostream>

using namespace std;

int main(void) {
    int r, c;
    cin >> r >> c;

    char paper[50][51];
    for (int i = 0; i < r; i++)
        cin >> paper[i];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c / 2; j++) {
            int opp = c - (j + 1);
            if (paper[i][j] == '.')
                paper[i][j] = paper[i][opp];
            else if (paper[i][opp] == '.')
                paper[i][opp] = paper[i][j];
        }

        cout << paper[i] << '\n';
    }

    return 0;
}
