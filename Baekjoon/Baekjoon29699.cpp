#include <iostream>

#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    string ans = "WelcomeToSMUPC";

    int n;
    cin >> n;

    n--;

    int a = n % 14;
    cout << ans[a] << '\n';

    return 0;
}
