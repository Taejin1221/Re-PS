// Baekjoon30805.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

struct Node {
    int val;
    pii pos;

    Node(int v, int i, int j): val(v), pos({ i, j }) { }
};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr1[100];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];

    int m;
    cin >> m;

    int arr2[100];
    for (int i = 0; i < m; i++)
        cin >> arr2[i];

    vector<Node> stck;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr1[i] == arr2[j]) {
                vector<Node> popList;
                while (!stck.empty() && stck.back().val < arr1[i]) {
                    popList.push_back(stck.back());
                    stck.pop_back();
                }

                if (stck.empty())
                    stck.push_back(Node(arr1[i], i, j));
                else {
                    if (stck.back().val >= arr1[i]) {
                        if (stck.back().pos.first < i && stck.back().pos.second < j)
                            stck.push_back(Node(arr1[i], i, j));
                        else {
                            while (!popList.empty()) {
                                stck.push_back(popList.back());
                                popList.pop_back();
                            }
                        }
                    }
                }
            }
        }
    }

    cout << stck.size() << '\n';
    for (int i = 0; i < stck.size(); i++)
        cout << stck[i].val << ' ';
    cout << '\n';

    return 0;
}