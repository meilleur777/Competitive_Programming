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

set<string> e;
vector<bool> ok;
vector<string> sf, sb;

bool cpr(const int a, const int b) {
	string af=sf[a], bf=sf[b];
	string ab=sb[a], bb=sb[b];
	if (af==bf) {
		if (ok[a] && !ok[b]) return true;
		if (!ok[a] && ok[b]) return false;
		return ab<bb;
	}
	return af<bf;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	vector<string> s(N);
	vector<int> ind(N);
	ok=vector<bool>(N, false);
	rep(i, N) cin >> s[i];
	rep(i, N) {
		ind[i]=i;
		string t;
		cin >> t;
		e.insert(t);
	}
	sf.resize(N), sb.resize(N);
	for (int i=0; i<N; i++) {
		auto dot=s[i].find('.');
		string f(s[i].begin(), dot+s[i].begin());
		string b(dot+s[i].begin()+1, s[i].end());
		if (e.find(b)!=e.end()) ok[i]=true;	
		sf[i]=f, sb[i]=b;
	}
	sort(ind.begin(), ind.end(), cpr);
	for (auto i : ind) cout << s[i] << '\n';

	return 0;
}
