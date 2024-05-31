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

int main() {
	init_code();

	int N;
	cin >> N;
	vector<ll> A(N);
	rep(i, N) cin >> A[i];
	sort(A.begin(), A.end());
	if (N%2==0) {
		ll sum1=0;
		for (int i=0; i<N/2-1; i++) {
			sum1-=A[i]*2;
		}
		sum1-=A[N/2-1];
		sum1+=A[N/2];
		for (int i=N/2+1; i<N; i++) {
			sum1+=A[i]*2;
		}
		if (sum1<0) sum1*=-1;
		cout << sum1;
	}
	else {
		ll sum2=0;
		for (int i=0; i<N/2; i++) {
			sum2-=2*A[i];
		}
		sum2+=A[N/2];
		sum2+=A[N/2+1];
		for (int i=N/2+2; i<N; i++) {
			sum2+=A[i]*2;
		}
		if (sum2<0) sum2*=-1;

		ll sum3=0;
		for (int i=0; i<N/2-1; i++) {
			sum3-=2*A[i];
		}
		sum3-=A[N/2-1];
		sum3-=A[N/2];
		for (int i=N/2+1; i<N; i++) {
			sum3+=A[i]*2;
		}
		if (sum3<0) sum3*=-1;
		cout << max(sum2, sum3);
	}

	return 0;
}
