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

	ll N, K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end(), greater<ll>());
	ll left=-1, right=1e9*2;
	while (left+1<right) {
		ll mid=(left+right)/2;
		ll sum=0;
		for (int i=0; i<N; i++) {
			if (A[i]>mid) {
				sum+=A[i]-mid+1;
			}
		}
		if (sum>K) {
			left=mid;
		}
		else {
			right=mid;
		}
	}
	ll ans=0;
	for (int i=0; i<N; i++) {
		if (A[i]>right) {
			ans+=(A[i]+right+1)*(A[i]-right)/2;
			K-=A[i]-right;
		}
	}
	ans+=K*right;
	cout << ans;

	return 0;
}
