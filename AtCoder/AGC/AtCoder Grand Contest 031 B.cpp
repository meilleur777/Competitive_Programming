#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

int N;
vector<int> C;
vector<int> cache;
vector<vector<int> > memo;

int solve(int now) {
	if (now==N+1) {
		return 1;
	}
	int& ret=cache[now];
	if (ret!=-1) return ret;
	vector<int>::iterator it=upper_bound(memo[C[now]].begin(), memo[C[now]].end(), now);
	ret=0;
	if (it!=memo[C[now]].end() && *it!=now+1) {
		ret+=solve(*it);
		ret%=mod;
	}
	ret+=solve(now+1);
	ret%=mod;
	return ret;
}

int main() {
	init_code();

	cin >> N;
	C.resize(2e5+1);
	cache=vector<int>(N+1, -1);
	memo=vector<vector<int> >(2e5+1);
	for (int i=1; i<=N; i++) {
		cin >> C[i];
		memo[C[i]].push_back(i);
	}
	int tmp=solve(1);
	if (tmp==0) {
		cout << mod;
	}
	else cout << tmp;

	return 0;
}
