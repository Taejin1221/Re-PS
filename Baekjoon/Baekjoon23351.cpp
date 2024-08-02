// Baekjoon23351.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    vector<int> catnip(n, k);
    
    int ans = 0;
    bool run = true;
    while (run) {
        ans++;
        int minValStart = 0;
        for (int i = 0; i < n; i++)
            if (catnip[i] < catnip[minValStart])
                minValStart = i;

        for (int i = 0; i < a; i++)
            catnip[minValStart + i] += b;

        for (int i = 0; i < n; i++) {
            if (--catnip[i] == 0)
                run = false;
        }
    }

    cout << ans << '\n';

    return 0;
}