// Baekjoon24336.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

using pii = pair<int, int>;

int getTimeDiff(int start, int end) {
    return end + (end >= start ? 0 : 1440) - start;
}

int main(void) {
    map<string, int> index;
    index.insert({"Seoul", 0});
    index.insert({"Yeongdeungpo", 1});
    index.insert({"Anyang", 2});
    index.insert({"Suwon", 3});
    index.insert({"Osan", 4});
    index.insert({"Seojeongri", 5});
    index.insert({"Pyeongtaek", 6});
    index.insert({"Seonghwan", 7});
    index.insert({"Cheonan", 8});
    index.insert({"Sojeongni", 9});
    index.insert({"Jeonui", 10});
    index.insert({"Jochiwon", 11});
    index.insert({"Bugang", 12});
    index.insert({"Sintanjin", 13});
    index.insert({"Daejeon", 14});
    index.insert({"Okcheon", 15});
    index.insert({"Iwon", 16});
    index.insert({"Jitan", 17});
    index.insert({"Simcheon", 18});
    index.insert({"Gakgye", 19});
    index.insert({"Yeongdong", 20});
    index.insert({"Hwanggan", 21});
    index.insert({"Chupungnyeong", 22});
    index.insert({"Gimcheon", 23});
    index.insert({"Gumi", 24});
    index.insert({"Sagok", 25});
    index.insert({"Yangmok", 26});
    index.insert({"Waegwan", 27});
    index.insert({"Sindong", 28});
    index.insert({"Daegu", 29});
    index.insert({"Dongdaegu", 30});
    index.insert({"Gyeongsan", 31});
    index.insert({"Namseonghyeon", 32});
    index.insert({"Cheongdo", 33});
    index.insert({"Sangdong", 34});
    index.insert({"Miryang", 35});
    index.insert({"Samnangjin", 36});
    index.insert({"Wondong", 37});
    index.insert({"Mulgeum", 38});
    index.insert({"Hwamyeong", 39});
    index.insert({"Gupo", 40});
    index.insert({"Sasang", 41});
    index.insert({"Busan", 42});

    double distance[43] = { 0.0, 9.1, 23.9, 41.5, 56.5, 66.5, 75.0, 84.4, 96.6, 107.4, 114.9, 129.3, 139.8, 151.9, 166.3, 182.5, 190.8, 196.4, 200.8, 204.6, 211.6, 226.2, 234.7, 253.8, 276.7, 281.3, 289.5, 296.0, 305.9, 323.1, 326.3, 338.6, 353.1, 361.8, 372.2, 381.6, 394.1, 403.2, 412.4, 421.8, 425.2, 430.3, 441.7 };

    int n, m;
    cin >> n >> m;

    pii time[43];
    for (int i = 0; i < n; i++) {
        string area, start, end;
        cin >> area >> start >> end;

        int idx = index.find(area)->second;

        if (start[0] != '-')
            time[idx].first = ((start[0] - '0') * 10 + (start[1] - '0')) * 60 + ((start[3] - '0') * 10 + (start[4] - '0'));

        if (end[0] != '-')
            time[idx].second = ((end[0] - '0') * 10 + (end[1] - '0')) * 60 + ((end[3] - '0') * 10 + (end[4] - '0'));
    }

    cout << fixed;
    cout.precision(6);

    while (m--) {
        string start, end;
        cin >> start >> end;

        int idx1 = index.find(start)->second, idx2 = index.find(end)->second;

        double distDiff = distance[idx2] - distance[idx1];
        double timeDiff = getTimeDiff(time[idx1].second, time[idx2].first) / 60.0;

        double ans = (distDiff / timeDiff);

        cout << (ans < 0 ? -ans : ans) << '\n';
    }

    return 0;
}
