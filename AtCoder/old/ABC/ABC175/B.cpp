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
	vector<int> l(n);
	rep(i, n) cin >> l[i];
	sort(l.begin(), l.end());
	int ans=0;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			for (int k=j+1; k<n; k++) {
				if (l[i]==l[j] || l[j]==l[k] || l[k]==l[i]) continue;
				if (l[k]<l[i]+l[j]) ans++;
			}
		}
	}
	cout << ans;

	return 0;
}
