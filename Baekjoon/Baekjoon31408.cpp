#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int record[100'001] = { 0, };
    int maxRecord = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        record[temp]++;
        maxRecord = max(maxRecord, record[temp]);
    }

    if (n - maxRecord >= maxRecord - 1)
        cout << "YES";
    else
        cout << "NO";
    cout << '\n';

    return 0;
}
