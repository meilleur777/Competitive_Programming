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

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll atob=a.first*b.second-b.first*a.second;
	ll btoc=b.first*c.second-c.first*b.second;
	ll ctoa=c.first*a.second-a.first*c.second;
	ll tmp=atob+btoc+ctoa;
	if (tmp!=0) tmp/=llabs(tmp);
	return tmp;
}

int main() {
	init_code();

	vector<pair<ll, ll> > v(4);
	rep(i, 4) cin >> v[i].first >> v[i].second;
	int a=ccw(v[0], v[1], v[2])*ccw(v[1], v[0], v[3]);
	int b=ccw(v[2], v[3], v[1])*ccw(v[3], v[2], v[0]);
	if (a==0 && b==0) {
		if (v[0]>v[1]) swap(v[0], v[1]);
		if (v[2]>v[3]) swap(v[2], v[3]);
		if (v[0]<=v[3] && v[1]>=v[2]) cout << 1;
		else cout << 0;
	}
	else if (a>=0 && b>=0) cout << 1;
	else cout << 0;

	return 0;
}
