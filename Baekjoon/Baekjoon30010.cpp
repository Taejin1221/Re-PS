#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 3; i <= n; i++)
        cout << i << ' ';
    cout << "1 2\n";

    return 0;
}
