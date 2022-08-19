#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	map<string, ld> mp;
	mp["kg"]=2.2046;
	mp["lb"]=0.4536;
	mp["l"]=0.2642;
	mp["g"]=3.7854;

	map<string, string> mpp;
	mpp["kg"]="lb";
	mpp["lb"]="kg";
	mpp["l"]="g";
	mpp["g"]="l";

	int t;
	cin >> t;
	cout << fixed;
	cout.precision(4);
	while (t--) {
		ld a;
		string s;
		cin >> a >> s;
		cout << (ld)a*mp[s] << ' ' << mpp[s] << '\n';
	}

	return 0;
}
