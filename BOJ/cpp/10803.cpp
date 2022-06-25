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

vector<vector<int> > cache;

int solve(int N, int M) {
	if (N==M) return 1;
	if (M>N) swap(M, N);
	int& ret=cache[N][M];
	if (ret!=-1) return ret;
	ret=N*M;
	if (M*N%(M*M)==0) {
		return ret=N/M;
	}
	if (N>=M*3) {
		return ret=min(ret, solve(N-M, M)+1);
	}
	for (int i=1; i<=N/2; i++) {
		ret=min(ret, solve(i, M)+solve(N-i, M));
	}
	for (int i=1; i<=M/2; i++) {
		ret=min(ret, solve(N, i)+solve(N, M-i));
	}
	return ret;
}

int main() {
	init_code();

	int N, M;
	cin >> N >> M;
	if (M>N) swap(M, N);
	cache=vector<vector<int> >(N+1, vector<int>(M+1, -1));
	cout << solve(N, M);

	return 0;
}
