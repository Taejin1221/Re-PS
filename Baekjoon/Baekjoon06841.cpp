// Baekjoon06841.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    while (getline(cin, str)) {
        if (str == "CU")
            cout << "see you";
        else if (str == ":-)")
            cout << "I’m happy";
        else if (str == ":-(")
            cout << "I’m unhappy";
        else if (str == ";-)")
            cout << "wink";
        else if (str == ":-P")
            cout << "stick out my tongue";
        else if (str == "(~.~)")
            cout << "sleepy";
        else if (str == "TA")
            cout << "totally awesome";
        else if (str == "CCC")
            cout << "Canadian Computing Competition";
        else if (str == "CUZ")
            cout << "because";
        else if (str == "TY")
            cout << "thank-you";
        else if (str == "YW")
            cout << "you’re welcome";
        else if (str == "TTYL")
            cout << "talk to you later";
        else
            cout << str;
        cout << '\n';
    }

    return 0;
}
