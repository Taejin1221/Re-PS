// Baekjoon31563.cpp
#include <iostream>

using namespace std;

using ll = long long;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    int arr[200'000];
    ll prefix[200'001] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        prefix[i + 1] = prefix[i] + arr[i];
    }

    int start = 0, end = n - 1;
    while (q--) {
        int oper;
        cin >> oper;
        if (oper == 1) {
            int k;
            cin >> k;

            start = (start - k + n) % n;
            end = (end - k + n) % n;
        } else if (oper == 2) {
            int k;
            cin >> k;

            start = (start + k) % n;
            end = (end + k) % n;
        } else if (oper == 3) {
            int a, b;
            cin >> a >> b;

            int qStart = (start + (a - 1)) % n, qEnd = (start + (b - 1)) % n;
            if (qStart <= qEnd)
                cout << prefix[qEnd + 1] - prefix[qStart];
            else
                cout << (prefix[n] - prefix[qStart] + prefix[qEnd + 1]);
            cout << '\n';
        }
    }

    return 0;
}