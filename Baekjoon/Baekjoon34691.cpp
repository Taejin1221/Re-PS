// Baekjoon34691.cpp
#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;

    while (str != "end") {
        if (str == "animal")
            cout << "Panthera tigris";
        else if (str == "tree")
            cout << "Pinus densiflora";
        else if (str == "flower")
            cout << "Forsythia koreana";
        cout << '\n';

        cin >> str;
    }

    return 0;
}