#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] >= arr[i + 1]) {
            ans += arr[i] - (arr[i + 1] - 1);
            arr[i] = arr[i + 1] - 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
