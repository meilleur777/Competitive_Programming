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

	int h, w;
	cin >> h >> w;
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<int> > res(h, vector<int>(w));
	int ptr=0;
	for (int i=0; i<n; i++) {
		int tmp=a[i];
		while (tmp--) {
			res[ptr/w][ptr%w]=i+1;
			ptr++;
		}
	}
	for (int i=0; i<h; i++) {
		if (i&1) reverse(res[i].begin(), res[i].end());
		for (auto j:res[i]) {
			cout << j << ' ';
		}
		cout << '\n';
	}

	return 0;
}
