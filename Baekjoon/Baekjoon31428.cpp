// Baekjoon31428.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    char friends[10'000];
    for (int i = 0; i < n; i++)
        cin >> friends[i];
    
    char me;
    cin >> me;

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += friends[i] == me;

    cout << ans << '\n';

    return 0;
}