// Baekjoon01049.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    // set: 6세트 가격, one: 1개당 가격
    int set[100], one[100];
    for (int i = 0; i < m; i++)
        cin >> set[i] >> one[i];

    // 각자 가장 싼 가격 선택하기 위해 정렬
    sort(set, set + m);
    sort(one, one + m);

    int ans = 0;
    // 6개 낱개를 사는 것보다 6개 세트로 사는 것이 싼 경우
    if (set[0] < one[0] * 6) {
        // 6개 세트로 전부 구매
        ans += n / 6 * set[0]; n %= 6;

        // 남은 개수를 낱개로 사는 것보다 6개 세트로 사는 것이 싼 경우
        if (set[0] <= one[0] * n)
            ans += set[0];
        else
            ans += one[0] * n;
    } else {
        ans = one[0] * n;
    }

    cout << ans << '\n';

    return 0;
}