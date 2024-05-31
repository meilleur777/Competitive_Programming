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
const ll NEGINF=-1e14;

vector<ll> a;
vector<vector<ll> > cache;

ll getSum(int left, int right) {
	if (left>right) return 0;
	if (left==0) return a[right];
	return a[right]-a[left-1];
}

/*true->Taro, false->Jiro*/
ll solve(int left, int right) {
	if (left>right) {
		return 0;
	}
	ll& ret=cache[left][right];
	if (ret!=NEGINF) return ret;
	ret=max(ret, getSum(left+1, right)-solve(left+1, right)+getSum(left, left));
	ret=max(ret, getSum(left, right-1)-solve(left, right-1)+getSum(right, right));
	return ret;
}

int main() {
	init_code();

	int N;
	cin >> N;
	a.resize(N);
	cache=vector<vector<ll> >(N, vector<ll>(N, NEGINF));
	ll sum=0;
	rep(i, N) {
		cin >> a[i];
	}
	for (int i=1; i<N; i++) {
		a[i]+=a[i-1];
	}
	cout << 2*solve(0, N-1)-a[N-1];

	return 0;
}
