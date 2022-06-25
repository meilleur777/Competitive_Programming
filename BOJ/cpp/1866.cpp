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

int N, t, h;
vector<int> A;
vector<ll> psum;
vector<int> cache;

ll getSum(int start, int end) {
	if (start>end) return 0;
	if (start==0) return psum[end];
	return psum[end]-psum[start-1];
}

int solve(int now) {
	if (now==N) return 0;
	int& ret=cache[now];
	if (ret!=-1) return ret;
	ret=INF;
	for (int i=now; i<N; i++) {
		int mid=(now+i)/2;
		int tmp=A[mid]*(mid-now)-getSum(now, mid-1)+getSum(mid+1, i)-A[mid]*(i-mid);
		ret=min(ret, solve(i+1)+tmp*t+h);
	}	
	ret=min(ret, solve(now+1)+A[now]*t);
	return ret;
}

int main() {
	init_code();

	cin >> N;
	A.resize(N);
	cache=vector<int>(N, -1);
	rep(i, N) cin >> A[i];
	cin >> t >> h;
	sort(A.begin(), A.end());
	psum=vector<ll>(N, 0);
	psum[0]=A[0];
	for (int i=1; i<N; i++) {
		psum[i]+=psum[i-1]+A[i];
	}
	cout << solve(0);

	return 0;
}
