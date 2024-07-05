// Baekjoon28445.cpp
#include <iostream>

#include <set>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    set<string> colorTable;
    for (int i = 0; i < 4; i++) {
        string color;
        cin >> color;

        colorTable.insert(color);
    }

    vector<string> colors;
    for (auto iter = colorTable.begin(); iter != colorTable.end(); ++iter)
        colors.push_back(*iter);

    int n = colors.size();
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << colors[i] << ' ' << colors[j] << '\n';

    return 0;
}