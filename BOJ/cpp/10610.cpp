#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;


typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

int main() {
	init_code();

	string num;
	cin >> num;
	if (find(num.begin(), num.end(), '0') == num.end()) {
		cout << -1;
		return 0;
	}
	int sum = 0;
	rep(i, num.size()) {
		sum += num[i]-'0';
	}
	if (sum%3) {
		cout << -1;
		return 0;
	}
	sort(num.begin(), num.end(), greater<int>());
	cout << num;

	return 0;
}
