// Baekjoon17264.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    cin >> n >> p;

    int w, l, g;
    cin >> w >> l >> g;

    map<string, bool> isWin;
    for (int i = 0; i < p; i++) {
        string name; char w;
        cin >> name >> w;

        isWin.insert({ name, (w == 'W')});
    }

    int score = 0; bool iron = false;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;

        auto iter = isWin.find(name);
        if (iter == isWin.end() || !iter->second)
            score = max(0, score - l);
        else
            score += w;

        if (score >= g) {
            iron = true;
            break;
        }
    }

    cout << "I AM " << (iron ? "NOT " : "") << "IRONMAN!!\n";

    return 0;
}
