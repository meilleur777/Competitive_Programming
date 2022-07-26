#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;
	k--;
	vector<pair<int, intp>> a(n);
	rep(i, n) {
		int b, c, d, e;
		cin >> b >> c >> d >> e;
		a[b-1]={c, {d, e}};
	}
	int ans=1;
	rep(i, n) {
		if (i!=k && a[i]>a[k]) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
