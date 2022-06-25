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
	vector<int> p(n);
	vector<int> now(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
		now[p[i]]=i;
	}
	// for (auto i:now) cout << i << ' ';
	vector<int> ans;
	vector<bool> use(n+1, false);
	for (int i=0; i<n; i++) {
		while (now[i]>i) {
			if (use[now[i]]) {
				cout << -1;
				return 0;
			}
			ans.push_back(now[i]);
			use[now[i]]=true;
			swap(p[now[i]-1], p[now[i]]);
			now[i]--;
			// cout << now[i] << '\n';
			now[p[now[i]+1]]++;
			// cout << i << ' ' << p[now[i]+1] << ' ' << now[i] << '\n';
		}
	}
	// do the following N−1 operations on P, each <exactly> once
	if (ans.size()!=n-1) {
		cout << -1;
		return 0;
	}
	for (auto i:ans) cout << i << '\n';

	return 0;
}
