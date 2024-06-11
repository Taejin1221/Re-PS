// Baekjoon28702.cpp
#include <iostream>

#include <string>

#define IS_DIGIT(x) ('0' <= (x) && (x) <= '9')

using namespace std;

int stringToInteger(string& a) {
    int result = 0;
    for (char& n : a)
        result = result * 10 + (int)(n - '0');
    return result;
}

// 0 -> i, 1 -> Fizz, 2 -> Buzz, 3 -> FizzBuzz
int isFizzBuzz(int n) {
    int result = 0;
    if (n % 3 == 0)
        result += 1;
    if (n % 5 == 0)
        result += 2;

    return result;
}

int main(void) {
    string a, b, c;
    cin >> a >> b >> c;

    int num;
    if (IS_DIGIT(c[0]))
        num = stringToInteger(c) + 1;
    else if (IS_DIGIT(b[0]))
        num = stringToInteger(b) + 2;
    else
        num = stringToInteger(a) + 3;


    int ans = isFizzBuzz(num);
    if (ans == 0)
        cout << num;
    else if (ans == 1)
        cout << "Fizz";
    else if (ans == 2)
        cout << "Buzz";
    else
        cout << "FizzBuzz";
    cout << '\n';

    return 0;
}