// Baekjoon16236.cpp
#include <iostream>

#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

struct Node {
    int row, col, distance;

    Node(int r, int c, int d): row(r), col(c), distance(d) { }

    bool operator<(const Node& n2) const {
        return row != n2.row ? row < n2.row : col < n2.col;
    }
};

const int moves[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int n;
int sea[20][20];

Node bfs(Node start, int size) {
    queue<Node> q;
    bool visited[20][20] = { { false, }, };

    q.push(Node(start.row, start.col, 0));
    visited[start.row][start.col] = true;

    vector<Node> eatable;
    while (!q.empty()) {
        Node curr = q.front(); q.pop();

        if (sea[curr.row][curr.col] != 0 && sea[curr.row][curr.col] != size) {
            if (!eatable.empty()) {
                if (eatable.back().distance < curr.distance)
                    break;
                else
                    eatable.push_back(curr);
            } else
                eatable.push_back(curr);
        }

        for (int i = 0; i < 4; i++) {
            int newRow = curr.row + moves[i][0], newCol = curr.col + moves[i][1];
            if ((0 <= newRow && newRow < n) && (0 <= newCol && newCol < n)) {
                if (!visited[newRow][newCol] && sea[newRow][newCol] <= size) {
                    visited[newRow][newCol] = true;
                    q.push(Node(newRow, newCol, curr.distance + 1));
                }
            }
        }   
    }

    if (eatable.empty())
        return Node(-1, -1, -1);
    else {
        sort(eatable.begin(), eatable.end());

        return eatable[0];
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    Node shark = Node(0, 0, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> sea[i][j];

            if (sea[i][j] == 9) {
                sea[i][j] = 0;
                shark.row = i, shark.col = j;
            }
        }
    }

    int size = 2, eat = 0;
    while (1) {
        Node nextPos = bfs(shark, size);

        if (nextPos.distance == -1)
            break;
        else {
            shark.row = nextPos.row, shark.col = nextPos.col;
            shark.distance += nextPos.distance;

            sea[nextPos.row][nextPos.col] = 0;

            eat++;

            if (eat == size) {
                size++;
                eat = 0;
            }
        }
    }

    cout << shark.distance << '\n';

    return 0;
}