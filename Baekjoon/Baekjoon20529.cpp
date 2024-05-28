// Baekjoon20529.cpp
#include <iostream>

#include <map>
#include <string>

using namespace std;

int getDiff(string& a, string& b) {
    return ((a[0] != b[0]) + (a[1] != b[1]) + (a[2] != b[2]) + (a[3] != b[3]));
}

void solve() {
    int n;
    cin >> n;

    map<string, int> MBTIs;
    for (int i = 0; i < n; i++) {
        string mbti;
        cin >> mbti;

        if (MBTIs.find(mbti) == MBTIs.end())
            MBTIs.insert({ mbti, 1 });
        else
            MBTIs.find(mbti)->second++;
    }

    int ans = 100;
    for (auto iter1 = MBTIs.begin(); iter1 != MBTIs.end(); ++iter1) {
        if (iter1->second >= 3) {
            ans = 0;
            break;
        } else if (iter1->second == 2) {
            for (auto iter2 = MBTIs.begin(); iter2 != MBTIs.end(); ++iter2) {
                if (iter1->first != iter2->first) {
                    string mbti1 = iter1->first, mbti2 = iter2->first;

                    ans = min(ans, getDiff(mbti1, mbti2) * 2);
                }
            }
        } else {
            for (auto iter2 = MBTIs.begin(); iter2 != MBTIs.end(); ++iter2) {
                for (auto iter3 = MBTIs.begin(); iter3 != MBTIs.end(); ++iter3) {
                    if (iter1->first != iter2->first && iter2->first != iter3->first && iter3->first != iter1->first) {
                        string mbti1 = iter1->first, mbti2 = iter2->first, mbti3 = iter3->first;

                        ans = min(ans, getDiff(mbti1, mbti2) + getDiff(mbti2, mbti3) + getDiff(mbti3, mbti1));
                    }
                }
            }
        }
    }

    cout << ans << '\n';
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}