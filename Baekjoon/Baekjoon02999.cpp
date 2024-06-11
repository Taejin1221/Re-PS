// Baekjoon02999.cpp
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int main(void) {
    string message;
    cin >> message;

    int r, c, n = message.size();
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0)
            r = i, c = n / i;
    }

    vector<vector<char>> messageBox(r, vector<char> (c));
    for (int i = 0; i < c; i++)
        for (int j = 0; j < r; j++)
            messageBox[j][i] = message[i * r + j];
    
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cout << messageBox[i][j];
    cout << '\n';

    return 0;
}