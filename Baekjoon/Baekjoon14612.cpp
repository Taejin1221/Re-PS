// Baekjoon14612.cpp
#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

using pii = pair<int, int>;

int main(void) {
    int n, m;
    cin >> n >> m;

    vector<pii> postit;
    while (n--) {
        string oper;
        cin >> oper;

        if (oper == "order") {
            pii order;
            cin >> order.second >> order.first;

            postit.push_back(order);
        } else if (oper == "sort") {
            sort(postit.begin(), postit.end());
        } else {
            int target;
            cin >> target;

            int idx;
            for (idx = 0; idx < postit.size() && postit[idx].second != target; idx++);

            vector<pii> temp;
            for (int i = postit.size() - 1; i > idx; i--) {
                temp.push_back(postit.back());
                postit.pop_back();
            }
            postit.pop_back();
            while (!temp.empty()) {
                postit.push_back(temp.back());
                temp.pop_back();
            }
        }

        if (postit.empty())
            cout << "sleep";
        else
            for (pii& p : postit)
                cout << p.second << ' ';
        cout << '\n';
    }

    return 0;
}
