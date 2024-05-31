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

	string S;
	cin >> S;
	stack<char> a;
	for (int i = 0; i < S.size(); i++) {
		if (a.empty()) {
			a.push(S[i]);
		}
		else {
			if ((S[i] == '1' && a.top() == '0') || (S[i] == '0' && a.top() == '1')) {
				a.pop();
			}
			else {
				a.push(S[i]);
			}
		}
	}
	cout << S.size()-a.size();

	return 0;
}
