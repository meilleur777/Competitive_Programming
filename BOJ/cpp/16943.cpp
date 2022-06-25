#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string a, b;
	cin >> a >> b;
	sort(a.begin(), a.end());
	int ans=-1;
	int bt=stoi(b);
	do {
		int at=stoi(a);
		if (a[0]=='0') continue;
		if (at<bt) ans=max(ans, at);
	} while (next_permutation(a.begin(), a.end()));
	if (ans==0) cout << -1;
	else cout << ans;

	return 0;
}
