// Baekjoon32029.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;

    int homeworks[101] = { 0, };
    for (int i = 1; i <= n; i++)
        cin >> homeworks[i];
    sort(homeworks, homeworks + n + 1);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int x = 0; x < a; x++) {
            int currTime = 0, currAns = 0, j;
            for (j = 1; j <= i; j++) {
                currTime += a;
                while (j < i && currTime > homeworks[j])
                    j++;

                if (currTime <= homeworks[j])
                    currAns++;
            }

            currTime += b * x;

            for (int j = i + 1; j <= n; j++) {
                currTime += a - x;
                while (j < n && currTime > homeworks[j])
                    j++;

                if (currTime <= homeworks[j])
                    currAns++;
            }

            ans = max(ans, currAns);
        }
    }

    cout << ans << '\n';

    return 0;
}