#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	if (n==1) cout << 2;
	else if (n==2) cout << 4;
	else {
		n-=2;
		int ans=4;
		int now=2;
		for (int i=0; i<n; i++) {
			if (i%3==0 || i%3==2) now++;
			ans+=now;
		}
		cout << ans;
	}

	return 0;
}
