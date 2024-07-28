// Baekjoon12891.cpp
#include <iostream>

#include <string>

using namespace std;

bool check(int target[], int curr[]) {
    for (int i = 0; i < 4; i++)
        if (target[i] > curr[i])
            return false;

    return true;
}

int main(void) {
    int map[128];
    map['A'] = 0, map['C'] = 1, map['G'] = 2, map['T'] = 3;

    int n, m;
    cin >> n >> m;

    string dna;
    cin >> dna;

    int target[4];
    for (int i = 0; i < 4; i++)
        cin >> target[i];

    int left = 0, ans = 0;
    int currDNA[4] = { 0, };
    for (int right = 0; right < n; right++) {
        currDNA[map[dna[right]]]++;
        if (right >= m)
            currDNA[map[dna[left++]]]--;

        if (right - left + 1 == m && check(target, currDNA))
            ans++;
    }

    cout << ans << '\n';

    return 0;
}