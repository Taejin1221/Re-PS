// Baekjoon29733.cpp
#include <iostream>

using namespace std;

int main(void) {
    int maxRow, maxCol, maxHeight;
    cin >> maxRow >> maxCol >> maxHeight;

    char cube[100][100][101];
    for (int i = 0; i < maxHeight; i++)
        for (int j = 0; j < maxRow; j++)
            cin >> cube[i][j];

    int ans[100][100][100];
    for (int i = 0; i < maxHeight; i++) {
        for (int j = 0; j < maxRow; j++) {
            for (int k = 0; k < maxCol; k++) {
                if (cube[i][j][k] == '*')
                    cout << '*';
                else {
                    int result = 0;
                    for (int height = -1; height <= 1; height++) {
                        for (int row = -1; row <= 1; row++) {
                            for (int col = -1; col <= 1; col++) {
                                int newHeight = i + height, newRow = j + row, newCol = k + col;
                                if ((0 <= newHeight && newHeight < maxHeight) && (0 <= newRow && newRow < maxRow) && (0 <= newCol && newCol < maxCol)) {
                                    if (!(newHeight == i && newRow == j && newCol == k)) {
                                        if (cube[newHeight][newRow][newCol] == '*')
                                            result++;
                                    }
                                }
                            }
                        }
                    }

                    cout << result % 10;
                }
            }
            cout << '\n';
        }
    }

    return 0;
}