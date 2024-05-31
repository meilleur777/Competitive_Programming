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
	vector<int> a(N+1);
	rep(i, N) cin >> a[i+1];
	vector<int> b(N+1);
	for (int i=N; i>=1; i--) {
		int cnt=0;
		for (int j=i*2; j<=N; j+=i) {
			cnt+=b[j];
		}
		if (cnt%2!=a[i]) {
			b[i]=1;
		}
		else {
			b[i]=0;
		}
	}
	vector<int> res;
	int cnt=0;
	for (int i=1; i<=N; i++) {
		if (b[i]==1) {
			cnt++;
			res.push_back(i);
		}
	}
	cout << cnt << '\n';
	for (auto i : res) {
		cout << i << ' ';
	}

	return 0;
}
