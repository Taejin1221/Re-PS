// Baekjoon10798.cpp
#include <iostream>

#include <string>

using namespace std;

int main(){
    int maxSize = 0;
    string strs[5];
    for (int i = 0; i < 5; i++) {
        cin >> strs[i];
        maxSize = max(maxSize, (int)strs[i].size());
    }

    int idx = 0;
    while (idx < maxSize) {
        for (int i = 0; i < 5; i++)
            if (idx < strs[i].size())
                cout << strs[i][idx];
        idx++;
    }
    cout << '\n';

    return 0;
}