// Baekjoon17144.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

struct Position {
    int row, col;
    Position(): row(-1), col(-1) { }
    Position(int r, int c): row(r), col(c) { }
};

struct Room {
    int arr[50][50];
    int maxRow, maxCol;
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

void dustDiffusion(Room& room, vector<Position>& dusts) {
    int (*arr)[50] = room.arr, & maxRow = room.maxRow, & maxCol = room.maxCol;

    int nextArr[50][50] = { { 0, }, };
    for (Position& dust : dusts) {
        int diffuse = 0;
        for (int i = 0; i < 4; i++) {
            int nextRow = dust.row + moves[i][0], nextCol = dust.col + moves[i][1];
            if ((0 <= nextRow && nextRow < maxRow) && (0 <= nextCol && nextCol < maxCol)) {
                if (arr[nextRow][nextCol] != -1) {
                    nextArr[nextRow][nextCol] += arr[dust.row][dust.col] / 5;
                    diffuse += arr[dust.row][dust.col] / 5;
                }
            }
        }

        nextArr[dust.row][dust.col] += arr[dust.row][dust.col] - diffuse;
    }

    dusts.clear();
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            arr[i][j] = nextArr[i][j];
            if (arr[i][j] > 0)
                dusts.push_back(Position(i, j));
        }
    }
}

void blowAir(Room& room, pii airCleaner, vector<Position>& dusts) {
    int (*arr)[50] = room.arr, & maxRow = room.maxRow, & maxCol = room.maxCol;

    int top = airCleaner.first, bottom = airCleaner.second;

    // Up
    for (int i = top - 1; i > 0; i--)
        arr[i][0] = arr[i - 1][0];
    for (int i = 0; i < maxCol - 1; i++)
        arr[0][i] = arr[0][i + 1];
    for (int i = 0; i < top; i++)
        arr[i][maxCol - 1] = arr[i + 1][maxCol - 1];
    for (int i = maxCol - 1; i > 1; i--)
        arr[top][i] = arr[top][i - 1];
    arr[top][1] = 0;

    // Bottom
    for (int i = bottom + 1; i < maxRow - 1; i++)
        arr[i][0] = arr[i + 1][0];
    for (int i = 0; i < maxCol - 1; i++)
        arr[maxRow - 1][i] = arr[maxRow - 1][i + 1];
    for (int i = maxRow - 1; i > bottom; i--)
        arr[i][maxCol - 1] = arr[i - 1][maxCol - 1];
    for (int i = maxCol - 1; i > 1; i--)
        arr[bottom][i] = arr[bottom][i - 1];
    arr[bottom][1] = 0; 

    dusts.clear();
    for (int i = 0; i < maxRow; i++)
        for (int j = 0; j < maxCol; j++)
            if (arr[i][j] > 0)
                dusts.push_back(Position(i, j));
}

int main(void) {
    Room room = Room();
    vector<Position> dusts;
    pii airCleaner = { -1, -1 };

    int t;
    int& maxRow = room.maxRow, & maxCol = room.maxCol;
    cin >> maxRow >> maxCol >> t;

    int (*arr)[50] = room.arr;
    for (int i = 0; i < maxRow; i++) {
        for (int j = 0; j < maxCol; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) {
                if (airCleaner.first == -1)
                    airCleaner.first = i;
                else
                    airCleaner.second = i;
            } else if (arr[i][j] > 0)
                dusts.push_back(Position(i, j));
        }
    }

    while (t--) {
        dustDiffusion(room, dusts);
        arr[airCleaner.first][0] = -1;
        arr[airCleaner.second][0] = -1;

        blowAir(room, airCleaner, dusts);
    }

    int ans = 0;
    for (Position& dust : dusts)
        ans += arr[dust.row][dust.col];
    cout << ans << '\n';

    return 0;
}