#include <iostream>

using namespace std;

using ll = long long;

ll getGCD(ll a, ll b) {
    return (b ? getGCD(b, a % b) : a);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    ll prod = 1LL;
    int arr[9];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];

        prod *= arr[i];
    }

    ll sum = 0LL;
    for (int i = 0; i < n; i++)
        sum += prod / arr[i];

    ll gcd = prod >= sum ? getGCD(prod, sum) : getGCD(sum, prod);
    cout << (prod / gcd) << '/' << (sum / gcd) << '\n';

    return 0;
}
