#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    char answer[10'000];
    for (int i = 0; i < n; i++)
        cin >> answer[i];

    int ans = 0;
    for (int i = 0; i < n; i++) {
        char temp;
        cin >> temp;

        if (answer[i] == temp)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
