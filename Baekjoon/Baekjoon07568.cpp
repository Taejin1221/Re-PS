// Baekjoon07568.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n, info[50][2];

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> info[i][0] >> info[i][1];

    for (int i = 0; i < n; i++) {
        int result = 0;
        for (int j = 0; j < n; j++)
            if (info[i][0] < info[j][0] && info[i][1] < info[j][1])
                result++;
        
        cout << result + 1 << ' ';
    }
    cout << '\n';

    return 0;
}