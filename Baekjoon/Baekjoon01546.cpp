// Baekjoon01546.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int scores[1'000], maxVal = 0;
    for (int i = 0; i < n; i++) {
        cin >> scores[i];

        maxVal = max(maxVal, scores[i]);
    }

    double result = 0.0;
    for (int i = 0; i < n; i++)
        result += (double)scores[i] / maxVal * 100;

    cout << fixed;
    cout.precision(2);
    cout << result / n << '\n';

    return 0;
}