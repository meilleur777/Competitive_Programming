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

	int n;
	cin >> n;
	vector<int> v(n);
	rep(i, n) cin >> v[i];
	sort(v.begin(), v.end());
	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		cout << upper_bound(v.begin(), v.end(), a)-lower_bound(v.begin(), v.end(), a) << ' ';
	}

	return 0;
}
