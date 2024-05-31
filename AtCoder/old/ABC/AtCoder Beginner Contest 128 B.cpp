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

bool cpr(const pair<pair<string, int>, int>& a, const pair<pair<string, int>, int>& b) {
	if (a.first.first==b.first.first) {
		return a>b;
	}
	return a.first<b.first;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<pair<pair<string, int>, int> > v;
	rep(i, n) {
		string s;
		int p;
		cin >> s >> p;
		v.push_back({{s, p}, i+1});
	}
	sort(v.begin(), v.end(), cpr);
	rep(i, n) {
		cout << v[i].second << '\n';
	}

	return 0;
}
