#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	cin >> n;
	
	int e = 1001, h = 0;
	
	int arr[100];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		
		e = min(e, arr[i]);
		h = max(h, arr[i]);
	}
	
	if (e == arr[0])
		cout << "ez";
	else if (h == arr[0])
		cout << "hard";
	else
		cout << "?";
	cout << '\n';

    return 0;
}
