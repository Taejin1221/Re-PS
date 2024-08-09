// Baekjoon15565.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;

    int dolls[1'000'000];
    for (int i = 0; i < n; i++)
        cin >> dolls[i];

    int ans = 0x3f3f3f3f, leftIdx = 0, currLion = 0;
    for (int rightIdx = 0; rightIdx < n; rightIdx++) {
        if (dolls[rightIdx] == 1)
            currLion++;

        while (currLion >= k) {
            ans = min(ans, rightIdx - leftIdx + 1);
            if (dolls[leftIdx] == 1)
                currLion--;
            leftIdx++;
        }
    }

    cout << (ans == 0x3f3f3f3f ? -1 : ans) << '\n';

    return 0;
}