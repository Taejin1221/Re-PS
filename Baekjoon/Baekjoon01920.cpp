// Baekjoon01920.cpp
#include <iostream>

#include <set>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    set<int> arr;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        arr.insert(temp);
    }

    int m;
    cin >> m;
    while (m--) {
        int find;
        cin >> find;

        cout << ((arr.find(find) == arr.end()) ? 0 : 1) << '\n';
    }

    return 0;
}