// Baekjoon02966.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string correct;
    cin >> correct;

    string jjig[3] = {"ABC", "BABC", "CCAABB"};
    int ns[3] = { 3, 4, 6 };

    int ans[3] = { 0, }, big = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (correct[j] == jjig[i][j % ns[i]])
                ans[i]++;
        }

        big = max(big, ans[i]);
    }

    cout << big << '\n';
    if (ans[0] == big)
        cout << "Adrian\n";

    if (ans[1] == big)
        cout << "Bruno\n";

    if (ans[2] == big)
        cout << "Goran\n";

    return 0;
}
