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
	vector<int> ifw(n, 0);
	if (s[0]=='#') ifw[0]=1;
	for (int i=1; i<n; i++) {
		if (s[i]=='#') ifw[i]=ifw[i-1]+1;
		else ifw[i]=ifw[i-1];
	}
	vector<int> ifb(n, 0);
	if (s[n-1]=='.') ifb[n-1]=1;
	for (int i=n-2; i>=0; i--) {
		if (s[i]=='.') ifb[i]=ifb[i+1]+1;
		else ifb[i]=ifb[i+1];
	}
	int ans=INT_MAX;
	for (int i=0; i<n-1; i++) {
		ans=min(ans, ifw[i]+ifb[i+1]);
	}
	ans=min(ans, ifb[0]);
	ans=min(ans, ifw[n-1]);
	cout << ans;

	return 0;
}
