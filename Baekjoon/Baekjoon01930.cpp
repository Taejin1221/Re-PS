// Baekjoon01930.cpp
#include <iostream>

using namespace std;

bool isSame(int origin[], int rotation[]) {
    int ans = false;
    for (int i = 0; i < 3; i++) {
        bool result = true;
        for (int j = 0; j < 3; j++) {
            if (origin[j + 1] != rotation[i + j]) {
                result = false;
                break;
            }
        }

        if (result) {
            ans = true;
            break;
        }
    }

    return ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    while (k--) {
        int origin[4];
        for (int i = 0; i < 4; i++)
            cin >> origin[i];

        int target[4];
        for (int i = 0; i < 4; i++)
            cin >> target[i];

        bool ans = false;
        int rotation[6];
        if (origin[0] == target[0]) {
            for (int i = 1; i <= 3; i++)
                rotation[i - 1] = rotation[i + 2] = target[i];

            ans |= isSame(origin, rotation);
        }

        if (origin[0] == target[1]) {
            rotation[0] = rotation[3] = target[2];
            rotation[1] = rotation[4] = target[0];
            rotation[2] = rotation[5] = target[3];

            ans |= isSame(origin, rotation);
        }

        if (origin[0] == target[2]) {
            rotation[0] = rotation[3] = target[0];
            rotation[1] = rotation[4] = target[1];
            rotation[2] = rotation[5] = target[3];

            ans |= isSame(origin, rotation);
        }

        if (origin[0] == target[3]) {
            rotation[0] = rotation[3] = target[1];
            rotation[1] = rotation[4] = target[0];
            rotation[2] = rotation[5] = target[2];

            ans |= isSame(origin, rotation);
        }

        cout << (ans ? 1 : 0) << '\n';
    }

    return 0;
}
