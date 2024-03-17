// Baekjoon12789.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    vector<int> stck;
    int arrIdx = 0;
    bool isNice = true;
    for (int i = 1; i <= n; i++) {
        if (stck.size() != 0 && stck.back() == i)
            stck.pop_back();
        else {
            while (arrIdx < n && arr[arrIdx] != i)
                stck.push_back(arr[arrIdx++]);

            if (arrIdx < n && arr[arrIdx] == i)
                arrIdx++;
            else {
                isNice = false;
                break;
            }
        }
    }

    cout << (isNice ? "Nice" : "Sad") << '\n';

    return 0;
}