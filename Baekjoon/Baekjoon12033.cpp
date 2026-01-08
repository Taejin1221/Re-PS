// Baekjoon12033.cpp
#include <iostream>

#include <vector>

using namespace std;

using ll = long long;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int cnt = 1; cnt <= t; cnt++) {
        int n;
        cin >> n;
        
        n *= 2;
        
        int arr[8];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        vector<int> ans;
        bool visited[8] = { false, };
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            if (!visited[i]) {
                visited[i] = true;
                ans.push_back(curr);
                
                ll target = (ll)curr * 4 / 3;
                
                int j = i + 1;
                while (j < n && !(!visited[j] && arr[j] == target))
                    j++;
                visited[j] = true;
            }
        }
        
        cout << "Case #" << cnt << ": ";
        for (int a : ans)
            cout << a << ' ';
        cout << '\n';
    }

    return 0;
}
