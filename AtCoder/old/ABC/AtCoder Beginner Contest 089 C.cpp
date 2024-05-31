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
	map<char, ll> m;
	rep(i, n) {
		string s;
		cin >> s;
		m[s[0]]++;
	}
	ll ans=0;
	string t("MARCH");
	for (int i=0; i<5; i++) {
		for (int j=i+1; j<5; j++) {
			for (int k=j+1; k<5; k++) {
				ans+=m[t[i]]*m[t[j]]*m[t[k]];
			}
		}
	}
	cout << ans;

	return 0;
}
