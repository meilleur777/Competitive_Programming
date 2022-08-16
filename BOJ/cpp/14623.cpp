#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

ll convert(string a) {
	reverse(a.begin(), a.end());
	ll ret=0;
	for (int i=0; i<(int)a.size(); i++) {
		if (a[i]=='1') ret+=(1<<i);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	ll c=convert(a)*convert(b);
			
	vector<int> ans;
	int cnt=0;
	while (c) {
		ans.push_back(c%2);
		c/=2;
		cnt++;
	}
	reverse(ans.begin(), ans.end());
	for (auto i:ans) cout << i;

	return 0;
}
