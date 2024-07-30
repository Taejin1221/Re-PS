// Baekjoon01213.cpp
#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

int main(void) {
    string name;
    cin >> name;

    int n = name.size();

    // 사전 순 정렬
    sort(name.begin(), name.end());
    
    bool sorry = false; // 회문 체크 flag
    char palindrome[51] = { 0, };
    int left = 0, right = n - 1, middle = n / 2;
    for (int i = 0; i < n; i += 2) {
        if (i != n - 1 && name[i] == name[i + 1])
            palindrome[left++] = palindrome[right--] = name[i];
        else {
            // 처음 홀수개인 알파벳 만나면
            if (palindrome[middle] == 0)
                palindrome[middle] = name[i--];
            else { // 다른 알파벳이 이미 홀수개인 경우
                sorry = true;
                break;
            }
        }
    }

    if (sorry)
        cout << "I\'m Sorry Hansoo";
    else
        cout << palindrome;
    cout << '\n';

    return 0;
}