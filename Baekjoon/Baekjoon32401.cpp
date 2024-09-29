// Baekjoon32401.cpp
#include <iostream>

#include <string>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    string str;
    cin >> str;

    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A')
            a.push_back(i);
    }

    int ans = 0;
    for (int i = 0; !a.empty() && i < a.size() - 1; i++) {
        int n = 0, start = a[i] + 1, end = a[i + 1] - 1;
        for (int j = start; j <= end; j++) {
            if (str[j] == 'N')
                n++;
        }

        if (n == 1)
            ans++;
    }

    cout << ans << '\n';

    return 0;
}
