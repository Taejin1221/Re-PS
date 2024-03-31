// Baekjoon20920.cpp
#include <iostream>

#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> frequency;

bool compare(string& a, string& b) {
    int freA = frequency.find(a)->second, freB = frequency.find(b)->second;
    if (freA != freB)
        return freA > freB;
    else if (a.size() != b.size())
        return a.size() > b.size();
    else
        return (a.compare(b) < 0);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> arr;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        if (str.size() < m)
            continue;

        if (frequency.find(str) == frequency.end()) {
            frequency.insert({ str, 1 });
            arr.push_back(str);
        } else
            (frequency.find(str)->second)++;
    }
    sort(arr.begin(), arr.end(), compare);

    for (string& a : arr)
        cout << a << '\n';

    return 0;
}