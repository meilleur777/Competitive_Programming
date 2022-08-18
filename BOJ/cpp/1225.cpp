#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	ll ans=0;
	for (int i=0; i<(int)a.size(); i++) {
		for (int j=0; j<(int)b.size(); j++) {
			ans+=(a[i]-'0')*(b[j]-'0');
		}
	}
	cout << ans;

	return 0;
}
