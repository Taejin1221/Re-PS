// Baekjoon01541.cpp
#include <iostream>

#include <string>

using namespace std;

int calculate(string expr) {
    int result = 0;

    int curr = 0;
    for (char& e : expr) {
        if ('0' <= e && e <= '9') {
            curr *= 10;
            curr += (int)(e - '0');
        } else {
            result += curr;
            curr = 0;
        }
    }
    result += curr;

    return result;
}

int main(void) {
    string expression;
    cin >> expression;

    int n = expression.size();

    int idx;
    string frontExpr = "", backExpr = "";
    for (idx = 0; idx < n && expression[idx] != '-'; idx++)
        frontExpr.push_back(expression[idx]);
    idx++;
    for (; idx < n; idx++)
        backExpr.push_back(expression[idx]);

    cout << calculate(frontExpr) - calculate(backExpr) << '\n';

    return 0;
}