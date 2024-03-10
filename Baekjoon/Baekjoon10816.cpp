// Baekjoon10816.cpp
#include <iostream>

#include <map>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    map<int, int> cards;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        if (cards.find(num) == cards.end())
            cards.insert({ num, 1 });
        else
            (cards.find(num)->second)++;
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;

        auto iter = cards.find(num);
        cout << (iter != cards.end() ? iter->second : 0) << ' ';
    }
    cout << '\n';

    return 0;
}