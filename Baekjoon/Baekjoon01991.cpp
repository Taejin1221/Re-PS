// Baekjoon01991.cpp
#include <iostream>

#include <vector>
#include <string>

#define L first
#define R second

using namespace std;

using pii = pair<int, int>;

vector<pii> binaryTree;

string ans[3];

void preorder(int me) {
    ans[0].push_back(me + 'A');
    
    if (binaryTree[me].L != -1)
        preorder(binaryTree[me].L);

    if (binaryTree[me].R != -1)
        preorder(binaryTree[me].R);
}

void inorder(int me) {
    if (binaryTree[me].L != -1)
        inorder(binaryTree[me].L);

    ans[1].push_back(me + 'A');
    
    if (binaryTree[me].R != -1)
        inorder(binaryTree[me].R);
}

void postorder(int me) {
    if (binaryTree[me].L != -1)
        postorder(binaryTree[me].L);

    if (binaryTree[me].R != -1)
        postorder(binaryTree[me].R);
    
    ans[2].push_back(me + 'A');
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    binaryTree = vector<pii> (n);
    for (int i = 0; i < n; i++) {
        char u, l, r;
        cin >> u >> l >> r;

        binaryTree[u - 'A'].L = (l == '.') ? -1 : l - 'A';
        binaryTree[u - 'A'].R = (r == '.') ? -1 : r - 'A';
    }

    preorder(0);
    inorder(0);
    postorder(0);

    cout << ans[0] << '\n' << ans[1] << '\n' << ans[2] << '\n';

    return 0;
}