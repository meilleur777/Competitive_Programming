#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n;
	cin >> n;

	if (n==1) {
		cout << 0;
		return 0;
	}

	long long tmp=1;
	while (tmp*2<n) {
		tmp*=2;
	}

	long long ans=tmp-1+(n+1)/2;
	cout << ans;

	return 0;
}
