// Baekjoon16503.cpp
#include <iostream>

using namespace std;

int main(void) {
    int a, b, c;
    char o1, o2;

    cin >> a >> o1 >> b >> o2 >> c;

    int ans1 = 0, ans2 = 0;
    if (o1 == '+') {
        if (o2 == '+') {
            ans1 = a + b + c;
            ans2 = b + c + a;
        } else if (o2 == '-') {
            ans1 = a + b - c;
            ans2 = b - c + a;
        } else if (o2 == '*') {
            ans1 = (a + b) * c;
            ans2 = b * c + a;
        } else {
            ans1 = (a + b) / c;
            ans2 = a + (b / c);
        }
    } else if (o1 == '-') {
        if (o2 == '+') {
            ans1 = (a - b) + c;
            ans2 = a - (b + c);
        } else if (o2 == '-') {
            ans1 = (a - b) - c;
            ans2 = a - (b - c);
        } else if (o2 == '*') {
            ans1 = (a - b) * c;
            ans2 = a - (b * c);
        } else {
            ans1 = (a - b) / c;
            ans2 = a - (b / c);
        }
    } else if (o1 == '*') {
        if (o2 == '+') {
            ans1 = (a * b) + c;
            ans2 = a * (b + c);
        } else if (o2 == '-') {
            ans1 = (a * b) - c;
            ans2 = a * (b - c);
        } else if (o2 == '*') {
            ans1 = (a * b) * c;
            ans2 = a * (b * c);
        } else {
            ans1 = (a * b) / c;
            ans2 = a * (b / c);
        }
    } else {
        if (o2 == '+') {
            ans1 = (a / b) + c;
            ans2 = a / (b + c);
        } else if (o2 == '-') {
            ans1 = (a / b) - c;
            ans2 = a / (b - c);
        } else if (o2 == '*') {
            ans1 = (a / b) * c;
            ans2 = a / (b * c);
        } else {
            ans1 = (a / b) / c;
            ans2 = a / (b / c);
        }
    }

    cout << min(ans1, ans2) << '\n';
    cout << max(ans1, ans2) << '\n';

    return 0;
}