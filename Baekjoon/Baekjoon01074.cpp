// Baekjoon01074.cpp
#include <iostream>

#include <vector>

#define ROW first
#define COL second

using namespace std;

using pii = pair<int, int>;

int findTarget(int size, pii curr, pii target, int num) {
    if (size == 2) {
        return num + ((target.ROW - curr.ROW) * 2 + (target.COL - curr.COL));
    } else {
        int half = size / 2;
        if ((curr.ROW <= target.ROW && target.ROW < curr.ROW + half) && (curr.COL <= target.COL && target.COL < curr.COL + half)) {
            return findTarget(half, curr, target, num);
        } else if ((curr.ROW <= target.ROW && target.ROW < curr.ROW + half) && (curr.COL + half <= target.COL && target.COL < curr.COL + 2 * half)) {
            return findTarget(half, { curr.ROW, curr.COL + half }, target, num + half * half);
        } else if ((curr.ROW + half <= target.ROW && target.ROW < curr.ROW + 2 * half) && (curr.COL <= target.COL && target.COL < curr.COL + half)) {
            return findTarget(half, { curr.ROW + half, curr.COL }, target, num + 2 * (half * half));
        } else {
            return findTarget(half, { curr.ROW + half, curr.COL + half }, target, num + 3 * (half * half));
        }
    }
}

int main(void) {
    int n;
    cin >> n;

    int r, c;
    cin >> r >> c;

    cout << findTarget((1 << n), { 0, 0 }, { r, c }, 0) << '\n';

    return 0;
}