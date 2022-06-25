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
vector<int> A;
vector<ll> tree;

void update(int i, int x) {
	for (; i<tree.size(); i+=(i&-i)) {
		tree[i]+=x;
	}
}

ll getSum(ll end) {
	ll res=0;
	for (; end>0; end&=(end-1)) {
		res+=tree[end];
	}
	return res;
}

int main() {
	init_code();

	cin >> N;
	A.resize(N);
	vector<intp> B(N);
	rep(i, N) {
		cin >> A[i];
		B[i]={A[i], i};
	}
	sort(B.begin(), B.end(), greater<intp>());
	tree=vector<ll>(N+1, 0);
	ll cnt=0;
	for (int i=0; i<N; i++) {
		cnt+=getSum(B[i].second+1);
		update(B[i].second+1, 1);
	}
	cout << cnt << '\n';
	for (int i=0; i<N-1; i++) {
		cnt-=A[i];
		cnt+=N-A[i]-1;
		cout << cnt << '\n';
	}

	return 0;
}
