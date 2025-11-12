// Baekjoon14729.cpp
#include <iostream>

#define MAX 10

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    double arr[MAX];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);

    cout << fixed;
    cout.precision(3);

    for (int i = 0; i < 7; i++)
        cout << arr[i] << '\n';

    return 0;
}
