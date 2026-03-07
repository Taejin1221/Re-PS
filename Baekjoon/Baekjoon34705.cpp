#include <iostream>

using namespace std;

int x, y;
int arr[5];

bool solve(int idx, int sum) {
    if (idx == 5)
        return (x <= sum && sum <= y);
    else {
        bool result = false;
        result |= solve(idx + 1, sum + arr[idx]);
        result |= solve(idx + 1, sum);

        return result;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        cin >> x >> y;

        for (int i = 0; i < 5; i++)
            cin >> arr[i];

        if (solve(0, 0))
            cout << "YES";
        else
            cout << "NO";
        cout << '\n';
    }

    return 0;
}
