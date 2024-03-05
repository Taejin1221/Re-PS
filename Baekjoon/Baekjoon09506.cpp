// Baekjoon09506.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    while (n != -1) {
        int sum = 0;
        vector<int> divisors;
        for (int i = 1; i < n; i++) {
            if (n % i == 0) {
                sum += i;
                divisors.push_back(i);
            }
        }

        if (sum == n) {
            cout << n << " = ";
            for (int i = 0; i < (int)divisors.size() - 1; i++)
                cout << divisors[i] << " + ";
            cout << divisors.back();
        } else
            cout << n << " is NOT perfect.";
        cout << '\n';

        cin >> n;
    }

    return 0;
}