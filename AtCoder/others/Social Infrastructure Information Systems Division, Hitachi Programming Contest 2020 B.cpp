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

	int A, B, m;
	cin >> A >> B >> m;
	vector<int> a(A), b(B);
	rep(i, A) cin >> a[i];
	rep(i, B) cin >> b[i];
	int ans=*min_element(a.begin(), a.end())+*min_element(b.begin(), b.end());
	rep(i, m) {
		int x, y, c;
		cin >> x >> y >> c;
		int tmp=a[x-1]+b[y-1]-c;
		ans=min(ans, tmp);
	}
	cout << ans;

	return 0;
}
