// Baekjoon29197.cpp
#include <iostream>

#include <set>

using namespace std;

using pii = pair<int, int>;

int getGCD(int a, int b) {
    return (b ? getGCD(b, a % b) : a);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    set<pii> gradients;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;

        int posX = (x < 0 ? -x : x), posY = (y < 0 ? -y : y);
        int gcd = posX > posY ? getGCD(posX, posY) : getGCD(posY, posX);

        gradients.insert({ x / gcd, y / gcd });
    }

    cout << gradients.size() << '\n';

    return 0;
}
