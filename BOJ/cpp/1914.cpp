#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	string ans=to_string(pow(2, n));
	ans=ans.substr(0, ans.find('.'));
	ans.back()--;
	cout << ans << '\n';
    
	function<void(int, int, int, int)> hanoi=[&](int a, int b, int c, int now) {
		if (now==1) {
			cout << a << ' ' << c << '\n';
			return;
		}
		hanoi(a, c, b, now-1);
		hanoi(a, b, c, 1);
		hanoi(b, a, c, now-1);
	};
	if (n<=20) hanoi(1, 2, 3, n);

	return 0;
}
