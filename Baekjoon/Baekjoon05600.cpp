// Baekjoon05600.cpp
#include <iostream>

#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int A, B, C;
    cin >> A >> B >> C;

    int n;
    cin >> n;

    int trouble[1'001];
    fill(trouble, trouble + 1'001, 2);

    int check[1'000][3], results[1'000];
    for (int i = 0; i < n; i++) {
        cin >> check[i][0] >> check[i][1] >> check[i][2] >> results[i];

        if (results[i] == 1)
            trouble[check[i][0]] = trouble[check[i][1]] = trouble[check[i][2]] = 1;
    }

    for (int i = 0; i < n; i++) {
        int a = check[i][0], b = check[i][1], c = check[i][2];

        int good = (trouble[a] == 1) + (trouble[b] == 1) + (trouble[c] == 1);
        if (good == 2) {
            if (trouble[a] == 2)
                trouble[a] = 0;
            else if (trouble[b] == 2)
                trouble[b] = 0;
            else
                trouble[c] = 0;
        }
    }

    for (int i = 1; i <= (A + B + C); i++)
        cout << trouble[i] << '\n';

    return 0;
}