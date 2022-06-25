#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i=0; i<(n); i++)
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

int N, M;
vector<int> A;
vector<int> res;

void solve(int now, int sel) {
	if (sel==M) {
		for (auto i : res) {
			cout << i << ' ';	
		}
		cout << '\n';
		return;
	}
	if (now==N) {
		return;
	}
	res[sel]=A[now];
	solve(now+1, sel+1);
	solve(now+1, sel);
}

int main() {
	init_code();

	cin >> N >> M;
	A.resize(N);
	res.resize(M);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	solve(0, 0);

	return 0;
}
