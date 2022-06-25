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

	string s;
	cin >> s;
	vector<int> cnt(26, 0);
	ll ans=0;
	int n=s.size();
	for (int i=n-1; i>0; i--) {
		if (i+1<n && s[i-1]==s[i]) {
			ans+=(n-1)-(i+1)+1-cnt[s[i]-'a'];
			// cout << (n-1)-(i+1)+1-cnt[s[i]-'a'] << '\n';
			cnt=vector<int>(26, 0);
			cnt[s[i]-'a']+=(n-1)-(i+1)+1;
		}
		cnt[s[i]-'a']++;
	}
	cout << ans;

	return 0;
}
