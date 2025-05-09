#include <iostream>

#include <string>

using namespace std;

using psi = pair<string, int>;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    psi ans = { "", 0 };
    for (int i = 0; i < 7; i++) {
        string className;
        cin >> className;

        int students;
        cin >> students;

        if (ans.second < students)
            ans = { className, students };
    }

    cout << ans.first << '\n';
    
    return 0;
}
