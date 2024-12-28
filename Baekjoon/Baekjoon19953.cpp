// Baekjoon19953.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

struct MoveInfo {
    int x, y, direction, v;

    MoveInfo(int x, int y, int d, int v): x(x), y(y), direction(d), v(v) { }
};

// return: { cycle 시작까지 걸리는 초, cycle의 크기 }
pii getCycle(int v0, int m) {
    bool visited[10] = { false, };

    vector<int> stck;
    stck.push_back(v0);
    if (v0 < 10)
        visited[v0] = true;

    int nextV = (v0 * m) % 10;
    while (!visited[nextV]) {
        visited[nextV] = true;
        stck.push_back(nextV);

        nextV = (nextV * m) % 10;
    }

    pii result = { 0, 0 };
    for (int i = 0; i < stck.size(); i++) {
        if (stck[i] == nextV)
            result = { i, stck.size() - i };
    }

    int prev = result.second;
    while (result.second % 4)
        result.second += prev;

    return result;
}

MoveInfo moveT(pii currPos, int v, int m, int t, int direction) {
    for (int i = 0; i < t; i++) {
        switch (direction) {
        case 0:
            currPos.second += v;
            break;
        case 1:
            currPos.first += v;
            break;
        case 2:
            currPos.second -= v;
            break;
        case 3:
            currPos.first -= v;
            break;
        }

        direction = (direction + 1) % 4;
        v = (v * m) % 10;
    }

    return MoveInfo(currPos.first, currPos.second, direction, v);
}

int main(void) {
    int v, m, t;
    cin >> v >> m >> t;

    pii cycle = getCycle(v, m);

    MoveInfo curr = moveT({ 0, 0 }, v, m, cycle.first, 0);
    t -= cycle.first;

    MoveInfo afterCycle = moveT({ 0, 0 }, curr.v, m, cycle.second, curr.direction);

    int quo = t / cycle.second;
    curr.x += afterCycle.x * quo;
    curr.y += afterCycle.y * quo;

    int rem = t % cycle.second;
    MoveInfo ans = moveT({ curr.x, curr.y }, curr.v, m, rem, curr.direction);

    cout << ans.x << ' ' << ans.y << '\n';

    return 0;
}
