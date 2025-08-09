// Baekjoon21316.cpp
#include <iostream>

#include <vector>

using namespace std;

int main(void) {
    vector<int> adjList[13];
    for (int i = 0; i < 12; i++) {
        int a, b;
        cin >> a >> b;

        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    int ans = 0;
    for (int i = 1; i <= 12; i++) {
        if (adjList[i].size() == 3) {
            int adjDegreeSum = 0;
            for (int adj : adjList[i])
                adjDegreeSum += adjList[adj].size();

            if (adjDegreeSum == 6) {
                ans = i;
                break;
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
