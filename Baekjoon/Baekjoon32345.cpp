// Baekjoon32345.cpp
#include <iostream>

#include <string>

#define MOD 1'000'000'007

using namespace std;

int isVowel(char a) {
    return (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u');
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int q;
    cin >> q;
    while (q--) {
        string str;
        cin >> str;

        int n = str.size();

        int prev;
        for (prev = 0; prev < n && !isVowel(str[prev]); prev++);

        long long ans;
        if (prev == n)
            ans = -1;
        else {
            ans = 1;

            while (true) {
                int next;
                for (next = prev + 1; next < n && !isVowel(str[next]); next++);

                if (next == n)
                    break;
                else {
                    ans = (ans * (next - prev)) % MOD;
                }

                prev = next;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}