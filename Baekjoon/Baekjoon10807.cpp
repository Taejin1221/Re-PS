// Baekjoon10807.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int dest;
    cin >> dest;

    int ans = 0;
    for (int i = 0; i < n; i++)
        if (arr[i] == dest)
            ans++;

    cout << ans << '\n';

    return 0;
}