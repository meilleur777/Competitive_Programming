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

const ll mod=1e9+7;

int main() {
	init_code();

	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	ll B1=0;
	for (int i=0; i<A.size(); i++) {
		for (int j=i+1; j<A.size(); j++) {
			if (A[i]>A[j]) {
				B1++;
			}
		}
	}
	B1%=mod;
	ll B2=0;
	for (int i=0; i<A.size(); i++) {
		for (int j=0; j<A.size(); j++) {
			if (A[i]>A[j]) {
				B2++;
			}
		}
	}
	B2+=B1*2;
	B2%=mod;
	if (K==1) {
		cout << B1;
	}
	else if (K==2) {
		cout << B2;
	}	
	else {
		ll t;
		if (K%2) {
			t=(K-1)/2%mod;
			t*=K;
			t%=mod;

		}
		else {
			t=K/2%mod;
			t*=K-1;
			t%=mod;
		}
		ll q=(K*(K-2))%mod;
		ll res=(t*B2)%mod-(B1*q)%mod;
		if (res<0) res+=mod;
		cout << res;
	}

	return 0;
}
