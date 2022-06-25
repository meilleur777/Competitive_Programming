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

int ans=0;
int N, S;
vector<int> A;

void brute(int now, int sum) {
	if (now==N) {
		if (sum==S) {
			ans++;
		}
		return;
	}
	brute(now+1, sum);
	brute(now+1, sum+A[now]);
}

int main() {
	init_code();

	cin >> N >> S;
	A.resize(N);
	rep(i, N) cin >> A[i];
	brute(0, 0);
	if (S==0) ans--;
	cout << ans;

	return 0;
}
