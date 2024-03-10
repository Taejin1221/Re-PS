// Baekjoon07785.cpp
#include <iostream>

#include <set>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    set<string> list;
    for (int i = 0; i < n; i++) {
        string name, enter;
        cin >> name >> enter;

        if (enter == "enter")
            list.insert(name);
        else
            list.erase(name);
    }

    for (auto iter = list.rbegin(); iter != list.rend(); iter++)
        cout << *iter << '\n';

    return 0;
}