// Baekjoon02467.cpp
#include <iostream>

#include <vector>
#include <algorithm>

#define ABS(x) ((x) < 0 ? (-(x)) : (x))

#define V first
#define I second

using namespace std;

using pii = pair<int, int>;

int min(pii a) { return (a.first < a.second) ? a.first : a.second; }
int max(pii a) { return (a.first > a.second) ? a.first : a.second; }

bool compare(pii& a, int b) {
	return a.first < b;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n;
	
	int arr[100'000];
	vector<pii> pos, neg;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		(arr[i] >= 0 ? pos : neg).push_back({ arr[i], i });
	}
	n = pos.size(), m = neg.size();


	int ansVal = 2'000'000'000;
	pii ansIdx = { 0, 0 };
	if (n >= 2) {
		ansVal = pos[0].V + pos[1].V;
		ansIdx = { pos[0].I, pos[1].I };
	}

	if (m >= 2) {
		pii last1 = neg[m - 1], last2 = neg[m - 2];
		
		if (ABS(last1.first + last2.first) < ansVal) {
			ansVal = ABS(last1.V + last2.V);
			ansIdx = { last1.I, last2. I };
		}
	}

	for (int i = 0; i < m; i++) {
		int simIdx = lower_bound(pos.begin(), pos.end(), -(neg[i].V), compare) - pos.begin();

		if (simIdx >= 1 && ABS(pos[simIdx - 1].V + neg[i].V) < ansVal) {
			ansVal = ABS(pos[simIdx - 1].V + neg[i].V);
			ansIdx = { pos[simIdx - 1].I, neg[i].I };
		}

		if (simIdx < n && ABS(pos[simIdx].V + neg[i].V) < ansVal) {
			ansVal = ABS(pos[simIdx].V + neg[i].V);
			ansIdx = { pos[simIdx].I, neg[i].I };
		}
	}

	cout << arr[min(ansIdx)] << ' ' << arr[max(ansIdx)] << '\n';

	return 0;
}