// Baekjoon10886.cpp
#include <iostream>

using namespace std;

int main(void) {
    int n;
    cin >> n;

    int cute = 0;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        if (temp)
            cute++;
    }

    cout << "Junhee is ";
    if (cute <= n / 2)
        cout << "not ";
    cout << "cute!\n";

    return 0;
}
