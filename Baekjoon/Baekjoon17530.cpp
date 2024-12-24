// Baekjoon17530.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    bool canElect = true;
    int votes[10'000];
    cin >> votes[0];
    for (int i = 1; i < n; i++) {
        cin >> votes[i];

        if (votes[0] < votes[i])
            canElect = false;
    }

    cout << (canElect ? 'S' : 'N') << '\n';

    return 0;
}
