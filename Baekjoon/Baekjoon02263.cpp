// Baekjoon02263.cpp
#include <iostream>

using namespace std;

int idxTable[100'001], postorder[100'000];

void solve(int inStart, int inEnd, int poStart, int poEnd) {
    int size = inEnd - inStart + 1;
    if (size == 0)
        return;

    int root = postorder[poEnd];
    cout << root << ' ';

    int rootIdx = idxTable[root];

    int leftSize = rootIdx - inStart;
    solve(inStart, rootIdx - 1, poStart, poStart + leftSize - 1); // left subtree
    solve(rootIdx + 1, inEnd, poStart + leftSize, poEnd - 1); // right subtree
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        idxTable[temp] = i;
    }

    for (int i = 0; i < n; i++)
        cin >> postorder[i];

    solve(0, n - 1, 0, n - 1);

    cout << '\n';

    return 0;
}