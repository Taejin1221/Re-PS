// Baekjoon05464.cpp
#include <iostream>

#include <queue>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int park[100];
    for (int i = 0; i < n; i++)
        cin >> park[i];

    int weight[2'001];
    for (int i = 1; i <= m; i++)
        cin >> weight[i];

    // parkCar: 현재 주차되어있는 차의 수, parkPos: 차가 주차되어있는 위치
    int parkCar = 0, parkPos[2'001] = { 0, };
    bool isPark[100] = { false, }; // 각 주차 위치가 주차되어있는지

    int ans = 0;
    queue<int> q;
    for (int t = 0; t < 2 * m; t++) {
        int newCar;
        cin >> newCar;

        if (newCar > 0) {
            q.push(newCar);
        } else {
            newCar *= -1;
            isPark[parkPos[newCar]] = false; // 해당 차가 주차되어있는 위치에서 차를 뺀다.
            parkCar -= 1;
        }

        while (parkCar < n && !q.empty()) {
            int pos;
            for (pos = 0; pos < n && isPark[pos]; pos++);

            // 가장 먼저 기다리고 있는 차를 가장 앞에 주차한다.
            int currCar = q.front(); q.pop();
            isPark[pos] = true;
            parkPos[currCar] = pos;
            parkCar++;

            ans += park[pos] * weight[currCar];
        }
    }

    cout << ans << '\n';

    return 0;
}
