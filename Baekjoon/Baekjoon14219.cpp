#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n % 3 == 0 || m % 3 == 0)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';

    return 0;
}
