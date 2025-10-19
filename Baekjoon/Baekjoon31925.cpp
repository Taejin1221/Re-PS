// Baekjoon31925.cpp
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Rank {
    string name;
    int rank;

    Rank(string n, int r): name(n), rank(r) {}

    bool operator<(const Rank& r2) const {
        return rank < r2.rank;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<Rank> arr;
    for (int i = 0; i < n; i++) {
        string name, hak, icpc;
        int shake, rank;

        cin >> name >> hak >> icpc >> shake >> rank;
        if (hak == "jaehak" && icpc == "notyet" && (shake > 3 || shake == -1))
            arr.push_back(Rank(name, rank));
    }
    sort(arr.begin(), arr.end());

    vector<string> ans;
    for (int i = 0; i < min(10, (int)arr.size()); i++)
        ans.push_back(arr[i].name);
    sort(ans.begin(), ans.end());

    cout << (int)ans.size() << '\n';
    for (string& s : ans)
        cout << s << '\n';

    return 0;
}
