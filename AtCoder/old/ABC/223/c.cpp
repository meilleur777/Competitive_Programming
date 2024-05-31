#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cout << fixed;
	cout.precision(10);

	int n;
	cin >> n;
	vector<ld> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	ld tim=0;
	rep(i, n) {
		tim+=a[i]/b[i];
	}
	tim/=2.0;
	ld ans=0;
	rep(i, n) {
		if (tim>a[i]/b[i]) {
			ans+=a[i];
			tim-=a[i]/b[i];
		}
		else {
			ans+=b[i]*tim;
			break;
		}
	}
	cout << ans;

	return 0;
}
