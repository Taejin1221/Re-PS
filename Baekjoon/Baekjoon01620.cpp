// Baekjoon01620.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    map<string, string> list;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;

        list.insert({ name, to_string(i) });
        list.insert({ to_string(i), name });
    }

    while (m--) {
        string query;
        cin >> query;

        cout << list.find(query)->second << '\n';
    }

    return 0;
}