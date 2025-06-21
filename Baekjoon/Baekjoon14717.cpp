#include <iostream>

#include <vector>

using namespace std;

int getScore(int a, int b) {
    if (a == b)
        return a + 10;
    else
        return (a + b) % 10;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;

    vector<int> arr;
    for (int i = 1; i <= 10; i++) {
        if (i != a)
            arr.push_back(i);
        if (i != b)
            arr.push_back(i);
    }

    int total = 0, win = 0;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (getScore(a, b) > getScore(arr[i], arr[j]))
                win++;
            total++;
        }
    }

    cout << fixed;
    cout.precision(3);

    cout << ((double)win / total) << '\n';

    return 0;
}
