#include <iostream>

using namespace std;

using pii = pair<int, int>;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
   int n;
   cin >> n;
   
   pii ans = { 0, 0 };
   for (int i = 2; i <= n; i++) {
   	int result = 0, temp = n;
	   
	   while (temp) {
	   	result += temp % i;
	   	temp /= i;
	   }
	   
	   if (ans.first < result)
	   	ans = { result, i };
   }
   
   cout << ans.first << ' ' << ans.second << '\n';
   
   return 0;
}

