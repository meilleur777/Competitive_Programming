#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int m;
	cin >> m;
	vector<int> b(m);
	rep(i, m) cin >> b[i];

	sort(a.begin(), a.end(), greater<int>());
	sort(b.begin(), b.end(), greater<int>());
	int ans=0;

	while (!b.empty()) {
		bool flag=false;
		for (int i=0; i<n; i++) {
			for (int j=0; j<(int)b.size(); j++) {
				if (a[i]>=b[j]) {
					b.erase(b.begin()+j);
					flag=true;
					break;
				}
			}
		}
		ans++;
		if (!flag) {
			cout << -1;
			return 0;
		}
	}
	cout << ans;

	return 0;
}
