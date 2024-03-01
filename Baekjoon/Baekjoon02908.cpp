// Baekjoon02908.cpp
#include <iostream>

#include <string>

using namespace std;

int reverseToInt(string& str) {
    int result = 0;
    for (auto iter = str.rbegin(); iter != str.rend(); iter++) {
        result *= 10;
        result += *iter - '0';
    }

    return result;
}

int main(void) {
    string str1, str2;
    cin >> str1 >> str2;

    int num1 = reverseToInt(str1), num2 = reverseToInt(str2);
    
    cout << ((num1 > num2) ? num1 : num2) << '\n';

    return 0;
}