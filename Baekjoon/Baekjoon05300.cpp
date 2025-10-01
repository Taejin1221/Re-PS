#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int cnt = 1;
    for (int i = 1; i <= n; i++, cnt++) {
        if (cnt > 6) {
            cout << "Go! ";
            cnt = 1;
        }
        cout << i << ' ';
    }

    if (cnt != 6)
        cout << "Go!\n";

    return 0;
}
