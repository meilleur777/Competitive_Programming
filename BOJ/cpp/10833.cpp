#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int ans=0;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		ans+=b%a; 
	}
	cout << ans;

	return 0;
}
