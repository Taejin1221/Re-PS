#include <iostream>

using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int s = a + b + c + d;
    cin >> a >> b >> c >> d;

    int m = a + b + c + d;

    cout << max(s, m) << '\n';

    return 0;
}
