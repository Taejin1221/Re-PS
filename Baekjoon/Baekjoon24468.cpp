// Baekjoon24468.cpp
#include <iostream>

using namespace std;

struct Ball {
    int pos, direction;
};

int main(void) {
    int l, n, t;
    cin >> l >> n >> t;

    Ball balls[100];
    for (int i = 0; i < n; i++) {
        int pos;
        char direction;
        cin >> pos >> direction;

        balls[i].pos = pos;
        balls[i].direction = direction == 'R' ? 1 : -1;

    }

    int ans = 0;
    while (t--) {
        for (int i = 0; i < n; i++)
            balls[i].pos += balls[i].direction;

        for (int i = 0; i < n; i++) {
            if ((balls[i].pos == 0 && balls[i].direction < 0) || (balls[i].pos == l && balls[i].direction > 0))
                balls[i].direction *= -1;
            else {
                for (int j = i + 1; j < n; j++) {
                    if (balls[i].pos == balls[j].pos) {
                        balls[i].direction *= -1;
                        balls[j].direction *= -1;
                        ans++;
                        break;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
