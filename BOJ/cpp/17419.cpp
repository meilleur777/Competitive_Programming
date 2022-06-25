#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, ans=0;
	string k;	
	cin >> n >> k;
	rep(i, n) ans+=k[i]=='1';
	cout << ans;

	return 0;
}
