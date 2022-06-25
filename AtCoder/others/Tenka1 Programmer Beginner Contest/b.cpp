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
	vector<intp> a(n);
	rep(i, n) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end());
	for (int i=0; i<n-1; i++) {
		if (a[i].second<=a[i+1].second) {
			cout << 0;
			return 0;
		}
	}
	cout << a.back().first+a.back().second;


	return 0;
}
