#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> tree(n);
	for (int i=0; i<n; i++) {
		cin >> tree[i];
	}
	sort(tree.begin(), tree.end());
	int a=tree[1]-tree[0];
	for (int i=0; i<n-1; i++) {
		a=__gcd(a, tree[i+1]-tree[i]);
	}
	ll ans=0;
	for (int i=0; i<n-1; i++) {
		ans+=(tree[i+1]-tree[i])/a-1;
	}
	cout << ans;

	return 0;
}
