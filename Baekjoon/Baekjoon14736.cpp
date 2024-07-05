// Baekjoon14736.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k, a;
    cin >> n >> k >> a;

    int ans = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        int t, s;
        cin >> t >> s;

        int drinked = 0, result = 0, prevResult = 0;
        while (drinked < k) {
            drinked += a;
            result++;
            if (drinked >= k)
                break;
            if (prevResult + t == result) {
                result += s;
                prevResult = result;
            }
        }

        ans = min(ans, result);
    }

    cout << ans << '\n';

    return 0;
}