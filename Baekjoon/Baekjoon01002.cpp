// Baekjoon01002.cpp
#include <iostream>

using namespace std;

int main(void) {
    int t;
    cin >> t;

    while (t--) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;

        int bigR = max(r1, r2), smallR = min(r1, r2);

        int distanceSqure = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        if (x1 == x2 && y1 == y2) { // 두 원의 중심이 같을 때
            if (r1 == r2)
                cout << -1;
            else
                cout << 0;
        } else if (bigR * bigR <= distanceSqure) { // 두 원의 중심이 서로의 원 둘레나 바깥에 있을 때
            int rSquare = (r1 + r2) * (r1 + r2);
            if (distanceSqure > rSquare)
                cout << 0;
            else if (distanceSqure < rSquare)
                cout << 2;
            else
                cout << 1;
        } else { // 한 원의 중심의 다른 원 안에 있을 때
            int rSquare = (bigR - smallR) * (bigR - smallR);
            if (distanceSqure > rSquare)
                cout << 2;
            else if (distanceSqure < rSquare)
                cout << 0;
            else
                cout << 2;
        }
        cout << '\n';
    }

    return 0;
}
