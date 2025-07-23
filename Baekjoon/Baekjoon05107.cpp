#include <iostream>

#include <map>
#include <vector>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int time = 1;
    while (n) {
        map<string, int> studentId;
        int adj[20];
        for (int i = 0; i < n; i++) {
            string from, to;
            cin >> from >> to;

            int fromId;
            auto fromIter = studentId.find(from);
            if (fromIter == studentId.end()) {
                fromId = studentId.size();
                studentId.insert({ from, fromId });
            } else
                fromId = fromIter->second;

            int toId;
            auto toIter = studentId.find(to);
            if (toIter == studentId.end()) {
                toId = studentId.size();
                studentId.insert({ to, toId });
            } else
                toId = toIter->second;

            adj[fromId] = toId;
        }

        int ans = 0;
        bool visited[20] = { false, };
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                for (int curr = i; !visited[curr]; curr = adj[curr])
                    visited[curr] = true;
                ans++;
            }
        }

        cout << time << ' ' << ans << '\n';

        cin >> n;
        time++;
    }

    return 0;
}
