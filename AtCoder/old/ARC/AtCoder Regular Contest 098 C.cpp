#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	init_code();

	int n;
	string s;
	cin >> n >> s;
	vector<int> cnte(n, 0), cntw(n, 0);
	if (s[0]=='W') cntw[0]=1;
	for (int i=1; i<n; i++) {
		cntw[i]=cntw[i-1];
		if (s[i]=='W') cntw[i]++;
	}
	if (s[n-1]=='E') cnte[n-1]=1;
	for (int i=n-2; i>=0; i--) {
		cnte[i]=cnte[i+1];
		if (s[i]=='E') cnte[i]++;
	}
	int res=INT_MAX;
	res=min(res, cnte[1]);
	res=min(res, cntw[n-1]);
	for (int i=0; i<n; i++) {
		res=min(res, cntw[i-1]+cnte[i+1]);
	}
	cout << res;

	return 0;
}
