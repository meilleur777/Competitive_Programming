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

	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	vector<intp> b(m);
	rep(i, m) cin >> b[i].second >> b[i].first;
	sort(b.begin(), b.end(), greater<intp>());
	int ptr=0;
	for (int i=0; i<m; i++) {
		bool flag=true;
		for (int j=0; j<b[i].second; j++) {
			if (a[ptr]>=b[i].first) {
				flag=false;
				break;
			}
			a[ptr]=b[i].first;
			ptr++;
		}
		if (flag==false) break;
	}
	ll ans=0;
	for (auto i:a) {
		ans+=i;
	}
	cout << ans;

	return 0;
}
