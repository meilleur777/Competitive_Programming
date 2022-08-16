#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map<int, int> mp;
		int t=n;
		for (int i=2; i*i<=n; i++) {
			while (t%i==0) {
				t/=i;
				mp[i]++;
			}
		}
		if (t!=1) mp[t]++;

		for (auto i:mp) {
			cout << i.first << ' ' << i.second << '\n';
		}
	}

	return 0;
}
