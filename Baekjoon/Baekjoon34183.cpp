#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    int needChair = n * 3 - m;
    if (needChair > 0)
        cout << max(0, needChair * a + b);
    else
        cout << 0;
    cout << '\n';

    return 0;
}
