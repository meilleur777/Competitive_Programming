#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int INF=0x3f3f3f3f;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<intp> v;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		if (a<b) continue;
		v.push_back({b, a});
	}
	sort(v.begin(), v.end());
	ll ans=m;
	int left=0, right=0;
	v.push_back({INF, INF});
	for (int i=1; i<(int)v.size(); i++) { 
		if (v[right].second<v[i].first) {
			ans+=2LL*(v[right].second-v[left].first);
			left=i, right=i;
		}
		else if (v[right].second<v[i].second) {
			right=i;
		}
	}
	cout << ans;

	return 0;
}
