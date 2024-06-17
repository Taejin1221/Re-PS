// Baekjoon30804.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int idx = 0;
    pii tanghuru[200'000] = { { 0, 1 }, };

    cin >> tanghuru[0].first;
    for (int i = 1; i < n; i++) {
        int fruit;
        cin >> fruit;

        if (tanghuru[idx].first != fruit)
            tanghuru[++idx] = { fruit, 1 };
        else
            tanghuru[idx].second++;
    }

    int ans;
    if (idx == 0)
        ans = tanghuru[0].second;
    else {
        int currFruit = ans = tanghuru[0].second + tanghuru[1].second;
        int fruitTypeNum = 1;

        bool fruitType[10] = { false, };
        fruitType[tanghuru[0].first] = true;
        fruitType[tanghuru[1].first] = true;

        for (int i = 2; i <= idx; i++) {
            if (fruitType[tanghuru[i].first]) {
                currFruit += tanghuru[i].second;
            } else {
                fruitType[tanghuru[i].first] = true;
                fruitType[tanghuru[i - 2].first] = false;

                currFruit = tanghuru[i].second + tanghuru[i - 1].second;
            }

            ans = max(ans, currFruit);
        }
    }

    cout << ans << '\n';

    return 0;
}