// Baekjoon15686.cpp
/*
최대 집의 개수 100(2 * n)

치킨집을 선택하는 최대 경우의 수 13C6 = 1287

치킨집 m개를 선택 후 모든 집에서의 치킨 거리를 체크
2n * m

총 100 * 13 * 1287 약 10^6
계산 아무리 잘못했어도 100까지는 가능


배열로 만들자
*/
#include <iostream>

#include <vector>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

using namespace std;

using pii = pair<int, int>;

int n ,m;
int ans = 0x3f3f3f3f;
vector<pii> home, chicken;

int getDistance(pii& a, pii& b) {
    return ABS(a.first - b.first) + ABS(a.second - b.second);
}

void solve(int idx, vector<int>& choice) {
    if (choice.size() == m) {
        int result = 0;
        for (int i = 0; i < home.size(); i++) {
            int chickenDistance = 0x3f3f3f3f;
            for (int j = 0; j < choice.size(); j++)
                chickenDistance = min(chickenDistance, getDistance(home[i], chicken[choice[j]]));
            result += chickenDistance;
        }

        ans = min(ans, result);
    } else {
        for (int i = idx; i < chicken.size(); i++) {
            solve(i + 1, choice);

            choice.push_back(i);
            solve(i + 1, choice);
            choice.pop_back();
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int kind;
            cin >> kind;

            if (kind == 1)
                home.push_back({ i, j });
            else if (kind == 2)
                chicken.push_back({ i, j });
        }
    }
    
    vector<int> choice;
    solve(0, choice);

    cout << ans << '\n';

    return 0;
}