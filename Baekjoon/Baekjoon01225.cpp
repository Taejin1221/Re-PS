#include <iostream>

#include <string>

using namespace std;

using ll = long long;

int main(void) {
    string a, b;
    cin >> a >> b;
    
    ll ans = 0;
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++)
            ans += (a[i] - '0') * (b[j] - '0');
    }
    
    cout << ans << '\n';
    
    return 0;
}
