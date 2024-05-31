#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
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
	cout << fixed;
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	vector<ld> p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]=(p[i]+1.0)/2.0;
	}
	ld sum=0;
	for (int i=0; i<k; i++) {
		sum+=p[i];
	}
	ld ans=sum;
	for (int i=k; i<n; i++) {
		sum-=p[i-k];
		sum+=p[i];
		ans=max(ans, sum);
	}
	cout << ans;

	return 0;
}
