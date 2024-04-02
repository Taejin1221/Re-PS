// Baekjoon14888.cpp
#include <iostream>

#include <vector>

using namespace std;

using pii = pair<int, int>;

int n, operands[4];
vector<int> nums;

pii ans = { 1'000'000'000, -1'000'000'000};

int calculate(vector<int>& currOperands) {
    int result = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        if (currOperands[i - 1] == 0)
            result += nums[i];
        else if (currOperands[i - 1] == 1)
            result -= nums[i];
        else if (currOperands[i - 1] == 2)
            result *= nums[i];
        else if (currOperands[i - 1] == 3)
            result /= nums[i];
    }

    return result;
}

void solve(vector<int>& currOperands, int idx) {
    if (idx + 1 == n) {
        int result = calculate(currOperands);
        ans.first = min(ans.first, result);
        ans.second = max(ans.second, result);
    } else {
        for (int i = 0; i < 4; i++) {
            if (operands[i]) {
                currOperands[idx] = i;
                operands[i]--;
                solve(currOperands, idx + 1);
                operands[i]++;
            }
        }
    }
}

int main(void) {
    cin >> n;

    nums = vector<int> (n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    for (int i = 0; i < 4; i++)
        cin >> operands[i];

    vector<int> currOperands(n - 1);
    solve(currOperands, 0);

    cout << ans.second << '\n' << ans.first << '\n';

    return 0;
}