// Baekjoon14646.cpp
#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	int ans = 0;
	int stickerNum = 0, sticker[100'001] = { 0, };
	for (int i = 0; i < 2 * n; i++) {
		int num;
		cin >> num;

		sticker[num]++;
		if (sticker[num] == 1)
			stickerNum += 1;
		else if (sticker[num] == 2)
			stickerNum -= 1;

		ans = max(ans, stickerNum);
	}

	cout << ans << '\n';

	return 0;
}
