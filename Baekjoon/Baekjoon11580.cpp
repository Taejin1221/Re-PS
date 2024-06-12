// Baekjoon11580.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n;
    cin >> n;

    string oper;
    cin >> oper;

    pii curr = { 0, 0 };

    set<pii> position;
    position.insert(curr);

    for (int i = 0; i < n; i++) {
        if (oper[i] == 'N')
            curr.first -= 1;
        else if (oper[i] == 'E')
            curr.second += 1;
        else if (oper[i] == 'S')
            curr.first += 1;
        else
            curr.second -= 1;

        position.insert(curr);
    }

    cout << position.size() << '\n';

    return 0;
}