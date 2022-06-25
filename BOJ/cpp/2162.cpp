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

vector<int> par;
vector<int> siz;
vector<pair<pair<ll, ll>, pair<ll, ll> > > v;

int find(int x) {
	if (x==par[x]) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
	siz[b]+=siz[a];
}

int ccw(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll atob=a.first*b.second-b.first*a.second;
	ll btoc=b.first*c.second-c.first*b.second;
	ll ctoa=c.first*a.second-a.first*c.second;
	ll tmp=atob+btoc+ctoa;
	if (tmp!=0) tmp/=llabs(tmp);
	return tmp;
}

bool chk(pair<pair<ll, ll>, pair<ll, ll> >& a, pair<pair<ll, ll>, pair<ll, ll> >& b) {
	int p=ccw(a.first, a.second, b.first)*ccw(a.second, a.first, b.second);
	int q=ccw(b.first, b.second, a.second)*ccw(b.second, b.first, a.first);
	if (p==0 && q==0) {
		if (a.first>a.second) swap(a.first, a.second);
		if (b.first>b.second) swap(b.first, b.second);
		if (a.first<=b.second && a.second>=b.first) return true;
		return false;
	}
	if (p>=0 && q>=0) return true;
	return false;
}

int main() {
	init_code();

	int n;
	cin >> n;
	v.resize(n);
	par=vector<int>(n);
	rep(i, n) par[i]=i;
	siz=vector<int>(n, 1);
	rep(i, n) cin >> v[i].first.first >> v[i].first.second >> v[i].second.first >> v[i].second.second;
	for (int i=0; i<n; i++) {
		for (int j=i+1; j<n; j++) {
			if (chk(v[i], v[j]) && find(i)!=find(j)) {
				merge(i, j);
			}
		}
	}
	set<int> gro;
	rep(i, n) gro.insert(find(i));
	cout << gro.size() << '\n' << *max_element(siz.begin(), siz.end());

	return 0;
}
