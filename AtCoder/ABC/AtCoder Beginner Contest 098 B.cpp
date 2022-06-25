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
	cin >> n;
	string s;
	cin >> s;
	int ans=-1;
	for (int i=1; i<n; i++) {
		string a(s.begin(), s.begin()+i);
		string b(s.begin()+i, s.end());
		vector<int> cnta(26, 0);
		vector<int> cntb(26, 0);
		for (auto j:a) {
			cnta[j-'a']++;
		}
		for (auto j:b) {
			cntb[j-'a']++;
		}
		int res=0;
		for (int i=0; i<26; i++) {
			int x=cnta[i]&&cntb[i];
			res+=x;
		}
		ans=max(res, ans);
	}
	cout << ans;

	return 0;
}
