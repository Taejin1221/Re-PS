#include <iostream>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int ans, t = 0;
    bool visited[1'001] ={ false, };
    for (int i = 2; i <= n; i++) {
        if (!visited[i]) {
            visited[i] = true;
            t++;
            if (t == k) {
                ans = i;
                break;
            }

            for (int j = i * i; j <= n; j += i) {
                if (!visited[j]) {
                    visited[j] = true;
                    t++;
                    if (t == k) {
                        ans = j;
                        break;
                    }
                }
            }

            if (t == k)
                break;
        }
    }

    cout << ans << '\n';
    
    return 0;
}
