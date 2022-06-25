#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

vector<ll> A;
vector<vector<ll> > cache;

/*last 1->switched, 0->not switched*/
ll solve(int now, int last) {
	if (now == A.size()-1) {
		if (last == 0) return A[now];
		else return -A[now];
	}

	ll& ret = cache[now][last];
	if (ret != -1) return ret;

	if (last == 0) {
		ret = max(ret, A[now]+solve(now+1, 0));
		ret = max(ret, -A[now]+solve(now+1, 1));
	}
	else if (last == 1) {
		ret = max(ret, -A[now]+solve(now+1, 0));
		ret = max(ret, A[now]+solve(now+1, 1));
	}
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	A.resize(N);
	rep(i, N) cin >> A[i];
	cache = vector<vector<ll> >(N, vector<ll>(3, -1));
	cout << max(A[0]+solve(1, 0), -A[0]+solve(1, 1));

	return 0;
}
