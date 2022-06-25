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
	int cnt=0;
	vector<int> A(S.size());
	for (int i=0; i<S.size(); i++) {
		if (S[i]=='W') {
			A[i]=cnt;
			cnt++;
		}
	}
	ll ans=0;
	for (int i=0; i<S.size(); i++) {
		if (S[i]=='W') {
			ans+=(ll)i-A[i];
		}
	}
	cout << ans;

	return 0;
}
