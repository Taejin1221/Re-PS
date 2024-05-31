// Baekjoon01918.cpp
#include <iostream>

#include <vector>
#include <string>

using namespace std;

int getPriority(char opr) {
    if (opr == '*' || opr == '/')
        return 3;
    else if (opr == '+' || opr == '-')
        return 2;
    else
        return 1;
}

int main(void) {
    string inorder;
    cin >> inorder;

    string postorder;
    vector<char> stck;

    for (char curr : inorder) {
        if ('A' <= curr && curr <= 'Z')
            postorder.push_back(curr);
        else {
            if (curr == '(')
                stck.push_back(curr);
            else if (curr == ')') {
                while (stck.back() != '(') {
                    postorder.push_back(stck.back());
                    stck.pop_back();
                }
                stck.pop_back();
            } else {
                while (!stck.empty() && getPriority(stck.back()) >= getPriority(curr)) {
                    postorder.push_back(stck.back());
                    stck.pop_back();
                }
                stck.push_back(curr);
            }
        }
    }

    while (!stck.empty()) {
        postorder.push_back(stck.back());
        stck.pop_back();
    }

    cout << postorder << '\n';

    return 0;
}