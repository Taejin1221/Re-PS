// Baekjoon02162.cpp
#include <iostream>

using namespace std;

using ll = long long;

struct Position {
    ll x, y;
};

ll getCCW(Position a, Position b, Position c) {
    return ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y));
}

struct Line {
    Position a, b;

    bool isIntersect(Line& target) {
        if (getCCW(a, b, target.a) == 0 && getCCW(a, b, target.b) == 0) {
            int maxX = max(a.x, b.x), minX = min(a.x, b.x);
            int maxY = max(a.y, b.y), minY = min(a.y, b.y);

            if (((minX <= target.a.x && target.a.x <= maxX) && (minY <= target.a.y && target.a.y <= maxY)) ||
                ((minX <= target.b.x && target.b.x <= maxX) && (minY <= target.b.y && target.b.y <= maxY))) {
                return true;
            } else {
                maxX = max(target.a.x, target.b.x), minX = min(target.a.x, target.b.x);
                maxY = max(target.a.y, target.b.y), minY = min(target.a.y, target.b.y);
                if (((minX <= a.x && a.x <= maxX) && (minY <= a.y && a.y <= maxY)) ||
                    ((minX <= b.x && b.x <= maxX) && (minY <= b.y && b.y <= maxY))) {
                    return true;
                }
            }
        } else if (getCCW(a, b, target.a) * getCCW(a, b, target.b) <= 0 && getCCW(target.a, target.b, a) * getCCW(target.a, target.b, b) <= 0)
            return true;

        return false;
    }
};

int parent[3'000], group[3'000];

int getRoot(int target) {
    return parent[target] = (parent[target] == target) ? target : getRoot(parent[target]);
}

void unionTwoTree(int aRoot, int bRoot) {
    if (aRoot < bRoot) {
        parent[bRoot] = aRoot;
        group[aRoot] += group[bRoot];
        group[bRoot] = 0;
    } else {
        parent[aRoot] = bRoot;
        group[bRoot] += group[aRoot];
        group[aRoot] = 0;
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    Line lines[3'000];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        group[i] = 1;

        cin >> lines[i].a.x >> lines[i].a.y >> lines[i].b.x >> lines[i].b.y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (lines[i].isIntersect(lines[j])) {
                int iRoot = getRoot(i), jRoot = getRoot(j);
                if (iRoot != jRoot)
                    unionTwoTree(iRoot, jRoot);
            }
        }
    }

    int groupNum = 0, maxGroup = 0;
    for (int i = 0; i < n; i++) {
        if (group[i])
            groupNum++;
        maxGroup = max(maxGroup, group[i]);
    }

    cout << groupNum << '\n';
    cout << maxGroup << '\n';

    return 0;
}
