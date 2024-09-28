// Baekjoon02902.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    string ans;
    for (int i = 0; i < str.size(); i++)
        if ('A' <= str[i] && str[i] <= 'Z')
            ans.push_back(str[i]);

    cout << ans << '\n';

    return 0;
}