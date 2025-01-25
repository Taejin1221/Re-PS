// Baekjoon28421.cpp
#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q;

    int arr[100'000];
    int table[10'001] = { 0, };
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        table[arr[i]]++;
    }

    while (q--) {
        int oper;
        cin >> oper;

        if (oper == 1) {
            int target;
            cin >> target;

            if (n <= 1) {
                cout << 0 << '\n';
                continue;
            }

            bool find = false;
            if (target == 0) {
                if (table[0])
                    find = true;
            } else {
                for (int i = 1; i <= 10'000; i++) {
                    if (target % i == 0) {
                        if (table[i] && (target / i <= 10'000 && table[target / i])) {
                            if (i * i == target) {
                                if (table[i] >= 2)
                                    find = true;
                            } else
                                find = true;
                        }
                    }

                    if (find)
                        break;
                }
            }

            cout << (find ? 1 : 0) << '\n';
        } else {
            int idx;
            cin >> idx;

            idx--;

            table[arr[idx]]--;
            arr[idx] = 0;
            table[arr[idx]]++;
        }
    }

    return 0;
}
