// Baekjoon10824.cpp
#include <iostream>

#include <string>

using namespace std;

using ll = long long;

int main(void) {
    ll a, c;
    string b, d;
    cin >> a >> b >> c >> d;

    ll ab = a;
    for (int i = 0; i < b.size(); i++) {
        ab *= 10LL;
        ab += (b[i] - '0');
    }

    ll cd = c;
    for (int i = 0; i < d.size(); i++) {
        cd *= 10LL;
        cd += (d[i] - '0');
    }

    cout << (ab + cd) << '\n';

    return 0;
}
