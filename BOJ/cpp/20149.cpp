#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;
typedef long double ld;


int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll atob=a.first*b.second-b.first*a.second;
	ll btoc=b.first*c.second-c.first*b.second;
	ll ctoa=c.first*a.second-a.first*c.second;
	ll tmp=atob+btoc+ctoa;
	if (tmp!=0) tmp/=llabs(tmp);
	return tmp;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << fixed;
	cout.precision(14);

	vector<pair<ll, ll>> v(4);
	rep(i, 4) cin >> v[i].first >> v[i].second;
	int a=ccw(v[0], v[1], v[2])*ccw(v[1], v[0], v[3]);
	int b=ccw(v[2], v[3], v[1])*ccw(v[3], v[2], v[0]);
	if (a==0 && b==0) {
		if (v[0]>v[1]) swap(v[0], v[1]);
		if (v[2]>v[3]) swap(v[2], v[3]);
		if (v[1]>=v[2] && v[0]<=v[3]) {
			cout << 1 << '\n';
			// 평행
			if ((v[1].second-v[0].second)*(v[3].first-v[2].first)==(v[3].second-v[2].second)*(v[1].first-v[0].first)) {
				if (v[1]==v[2] && v[0]<=v[2]) cout << v[1].first << ' ' << v[1].second;
				else if (v[0]==v[3] && v[2]<=v[0]) cout << v[0].first << ' ' << v[0].second;
			}
			else {
				ld a=(v[0].first*v[1].second-v[0].second*v[1].first)*(v[2].first-v[3].first)-(v[0].first-v[1].first)*(v[2].first*v[3].second-v[2].second*v[3].first);
				ld b=(v[0].first*v[1].second-v[0].second*v[1].first)*(v[2].second-v[3].second)-(v[0].second-v[1].second)*(v[2].first*v[3].second-v[2].second*v[3].first);
				ld c=(v[0].first-v[1].first)*(v[2].second-v[3].second)-(v[0].second-v[1].second)*(v[2].first-v[3].first);
				cout << a/c << ' ' << b/c;
 			}
		}
		else {
			cout << 0 << '\n';
		}
	}
	else if (a>=0 && b>=0) {
		cout << 1 << '\n';
		ld a=(v[0].first*v[1].second-v[0].second*v[1].first)*(v[2].first-v[3].first)-(v[0].first-v[1].first)*(v[2].first*v[3].second-v[2].second*v[3].first);
		ld b=(v[0].first*v[1].second-v[0].second*v[1].first)*(v[2].second-v[3].second)-(v[0].second-v[1].second)*(v[2].first*v[3].second-v[2].second*v[3].first);
		ld c=(v[0].first-v[1].first)*(v[2].second-v[3].second)-(v[0].second-v[1].second)*(v[2].first-v[3].first);
		cout << a/c << ' ' << b/c;
	}
	else cout << 0;

	return 0;
}
