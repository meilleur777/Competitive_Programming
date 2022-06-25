#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n;
	cin >> n;
	vector<int> a(10);
	rep(i, 10) a[i]=i;
	do {
		if (a[2]==0 || a[6]==0) continue;
		ll hello=a[2]*10000+a[1]*1000+a[3]*110+a[4];
		ll world=a[6]*10000+a[4]*1000+a[5]*100+a[3]*10+a[0];
		if (hello+world==n) {
			cout << "  " << to_string(hello) << '\n';
			cout << "+ " << to_string(world) << '\n';
			cout << "-------\n";
			cout << string(7-(int)to_string(n).size(), ' ') << to_string(n) << '\n';
			return 0;
		}
	} while (next_permutation(a.begin(), a.end()));
	cout << "No Answer";

	return 0;
}
