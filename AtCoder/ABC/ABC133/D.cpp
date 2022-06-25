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

int main() {
	init_code();

	int N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) {
		cin >> A[i];
		A[i]*=2;
	}
	ll tmp=0;
	for (int i=1; i<N; i++) {
		if (i%2) {	
			tmp-=A[i];
		}	
		else {
			tmp+=A[i];
		}
	}
	vector<ll> M(N);
	M[0]=(tmp+A[0])/2;
	for (int i=1; i<N; i++) {
		M[i]=A[i-1]-M[i-1];
	}
	rep(i, N) cout << M[i] << ' ';

	return 0;
}
