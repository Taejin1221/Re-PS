#include <iostream>

#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    string str;
    cin >> str;
    if (str == "SONGDO")
        cout << "HIGHSCHOOL";
    else if (str == "CODE")
        cout << "MASTER";
    else if (str == "2023")
        cout << "0611";
    else
        cout << "CONTEST";
    cout << '\n';
    
    return 0;
}
