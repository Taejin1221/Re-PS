#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int y = 0, m = 0;
    for (int i = 0; i < n; i++) {
        int mi;
        cin >> mi;

        y += (mi / 30 + 1) * 10;
        m += (mi / 60 + 1) * 15;
    }

    if (y < m)
        cout << "Y " << y;
    else if (y > m)
        cout << "M " << m;
    else
        cout << "Y M " << y;
    cout << '\n';

    return 0;
}
