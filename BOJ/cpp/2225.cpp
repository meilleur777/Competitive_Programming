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

const int mod=1e9;
const int INF=0x3F3F3F3F;

int N;
vector<vector<int> > cache;

int solve(int sum, int rem) {
	if (rem==0) {
		if (sum==N) return 1;
		else return 0;
	}
	int& ret=cache[sum][rem];
	if (ret!=-1) return ret;
	ret=0;
	for (int i=0; i<=N; i++) {
		if (sum+i<=N) {
			ret+=solve(sum+i, rem-1);
			ret%=mod;
		}	
		else break;
	}
	return ret;
}

int main() {
	init_code();

	int K;
	cin >> N >> K;
	cache=vector<vector<int> >(N+1, vector<int>(K+1, -1));
	cout << solve(0, K);

	return 0;
}
