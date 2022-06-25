#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vector<int> sco({6, 3, 2, 1, 2});
	rep(i, 2) {
		int ans=0;
		rep(j, 5) {
			int a;
			cin >> a;
			ans+=sco[j]*a;
		}
		cout << ans << '\n';
	}

	return 0;
}
