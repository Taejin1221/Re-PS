// Baekjoon23284.cpp
#include <iostream>

#include <vector>

using namespace std;

int n;
vector<int> curr;
bool visited[11];

void dfs(int biggest) {
    if (curr.size() == n) {
        for (auto i : curr)
            cout << i << ' ';
        cout << '\n';

        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            int nextBiggest = biggest;
            bool canPrint;
            if (biggest < i) {
                canPrint = true;
                nextBiggest = i;
            } else if (curr.size() > 0 && curr.back() > i) {
                canPrint = true;
                for (int j = i + 1; j <= biggest; j++) {
                    if (!visited[j]) {
                        canPrint = false;
                        break;
                    }
                }
            }

            if (canPrint) {
                visited[i] = true;
                curr.push_back(i);
                dfs(nextBiggest);
                curr.pop_back();
                visited[i] = false;
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cout.tie(0);

    cin >> n;

    dfs(0);

    return 0;
}
