// Baekjoon10815.cpp
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
        int num;
        cin >> num;

        arr.insert(num);
    }

    int t;
    cin >> t;
    while (t--) {
        int num;
        cin >> num;

        cout << ((arr.find(num) != arr.end()) ? 1 : 0) << ' ';
    }
    cout << '\n';

    return 0;
}