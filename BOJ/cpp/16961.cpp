#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<vector<int>> v(2, vector<int>(400, 0));

	int mxdd=0;
	for (int i=0; i<n; i++) {
		char c;
		int st, ed;
		cin >> c >> st >> ed;

		int tag=-1;
		if (c=='T') tag=0;
		else tag=1;

		for (int j=st; j<=ed; j++) {
			v[tag][j]+=1;
		}

		mxdd=max(mxdd, ed-st+1);
	}

	int ans=0;
	for (int i=1; i<=366; i++) {
		if (v[0][i]>0 || v[1][i]>0) ans++;
	}
	cout << ans << '\n';

	ans=0;
	for (int i=1; i<=366; i++) {
		ans=max(ans, v[0][i]+v[1][i]);
	}
	cout << ans << '\n';

	ans=0;
	int mx=0;
	for (int i=1; i<=366; i++) {
		bool tag=false;
		if (v[0][i]!=v[1][i]) tag=true;
		if (v[0][i]==0 || v[1][i]==0) tag=true;

		if (tag==false) ans++;

		if (tag==false) {
			mx=max(mx, v[0][i]+v[1][i]);
		}
	}
	cout << ans << '\n';
	cout << mx << '\n';
	cout << mxdd;	

	return 0;
}
