#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    if (n <= 10'000)
        cout << "Accepted";
    else
        cout << "Time limit exceeded";
    cout << '\n';

    return 0;
}
