// Baekjoon10874.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int score = 0;
        for (int j = 0; j < 10; j++) {
            int student;
            cin >> student;

            score += (student == (j % 5 + 1));
        }

        if (score == 10)
            cout << i << '\n';
    }

    return 0;
}
