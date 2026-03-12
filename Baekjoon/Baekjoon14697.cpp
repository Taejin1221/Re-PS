#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b, c, n;
    cin >> a >> b >> c >> n;

    bool find = false;
    for (int i = 0; i <= 300; i++) {
        for (int j = 0; j <= 300; j++) {
            for (int k = 0; k <= 300; k++) {
                if (a * i + b * j + c * k == n) {
                    find = true;
                    break;
                }
            }

            if (find)
                break;
        }

        if (find)
            break;
    }

    cout << (find ? 1: 0) << '\n';

    return 0;
}
