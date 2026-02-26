#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, w, h, l;
    cin >> n >> w >> h >> l;

    int a = w / l, b = h / l;
    cout << min(n, (a * b)) << '\n';

    return 0;
}
