#include <iostream>

#include <string>

using namespace std;

int main(void) {
    int n, oper;
    cin >> n >> oper;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (oper == 1) {
                if (str[j] == 'b')
                    cout << 'p';
                else if (str[j] == 'd')
                    cout << 'q';
                else if (str[j] == 'q')
                    cout << 'd';
                else
                    cout << 'b';
            } else {
                if (str[j] == 'b')
                    cout << 'd';
                else if (str[j] == 'd')
                    cout << 'b';
                else if (str[j] == 'q')
                    cout << 'p';
                else
                    cout << 'q';
            }
        }
        cout << '\n';
    }

    return 0;
}
