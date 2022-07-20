#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	vector<int> a(n), p(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> p[i];

	int ans=0;
	for (int i=0; i<(1<<n); i++) {
		int res=0;
		vector<int> tmp;
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				tmp.push_back(a[j]);
				res+=p[j];
			}
		}	

		int cnt=0;
		sort(tmp.begin(), tmp.end(), greater<int>());
		for (int j=0; j<(int)tmp.size(); j++) {
			cnt+=(j+1)*tmp[j];
		}

		if (cnt<=k) {
			ans=max(ans, res);
		}
	}
	cout << ans;

	return 0;
}

