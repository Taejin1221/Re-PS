// Baekjoon02477.cpp
#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int order[4][6] = {
        { 4, 2, 3, 1, 3, 1 },
        { 4, 1, 4, 2, 3, 1 },
        { 4, 2, 4, 2, 3, 1 },
        { 4, 2, 3, 2, 3, 1 }
    };

    int k;
    cin >> k;

    pii arr[12];
    for (int i = 0; i < 6; i++) {
        pii temp;
        cin >> temp.first >> temp.second;

        arr[i] = arr[i + 6] = temp;
    }

    int type, idx;
    for (int i = 0; i < 6; i++) {
        bool find;
        for (int j = 0; j < 4; j++) {
            find = true;
            for (int k = 0; k < 6; k++) {
                if (arr[i + k].first != order[j][k]) {
                    find = false;
                    break;
                }
            }

            if (find) {
                type = j;
                idx = i;
                break;
            }
        }

        if (find)
            break;
    }

    int ans = k;
    if (type == 0)
        ans *= (arr[idx].second * arr[idx + 1].second - arr[idx + 3].second * arr[idx + 4].second);
    else if (type == 1)
        ans *= (arr[idx + 3].second * arr[idx + 4].second - arr[idx].second * arr[idx + 1].second);
    else if (type == 2)
        ans *= (arr[idx + 4].second * arr[idx + 5].second - arr[idx + 1].second * arr[idx + 2].second);
    else
        ans *= (arr[idx].second * arr[idx + 5].second - arr[idx + 2].second * arr[idx + 3].second);

    cout << ans << '\n';

    return 0;
}
