#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[1'048'576];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k;
    cin >> k;

    int d = n / k;
    for (int i = 0; i < k; i++)
        sort(arr + i * d, arr + (i + 1) * d);

    for (int i = 0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}
