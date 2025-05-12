#include <iostream>

#include <map>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

void solve(int n, int m) {
    map<int, int> points;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;

            auto iter = points.find(num);
            if (iter == points.end())
                points.insert({ num, 1 });
            else
                iter->second++;
        }
    }

    vector<pii> pointsList;
    for (auto iter = points.begin(); iter != points.end(); ++iter)
        pointsList.push_back({ iter->second, iter->first });
    sort(pointsList.begin(), pointsList.end());

    int size = pointsList.size();

    int secondPoint = pointsList[size - 2].first;
    for (int i = 0; i < size - 1; i++)
        if (pointsList[i].first == secondPoint)
            cout << pointsList[i].second << ' ';
    cout << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;

    while (!(n == 0 && m == 0)) {
        solve(n, m);

        cin >> n >> m;
    }

    return 0;
}
