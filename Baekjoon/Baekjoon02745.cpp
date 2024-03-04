// Baekjoon02745.cpp
#include <iostream>

#include <string>

using namespace std;

int ctoi(char& c) {
    return ('0' <= c && c <= '9') ? ((int)(c - '0')) : ((int)(c - 'A') + 10);
}

int pow(int base, int exp) {
    return (exp == 0) ? 1 : (base * pow(base, exp - 1));
}

int main(void) {
    string str;
    int sys;
    cin >> str >> sys;

    int ans = 0, len = (int)str.size();
    for (int i = 0; i < len; i++)
        ans += ctoi(str[i]) * pow(sys, len - i - 1);

    cout << ans << '\n';

    return 0;
}