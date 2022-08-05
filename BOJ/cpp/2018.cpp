#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	int ans=0;
	// (a+b)*(b-a+1)/2==n
	for (int i=1; i<=n; i++) {
		if (n*2%i) continue;
		int ab=n*2/i;
		int ba=i-1;
		int b=ab+ba;
		int a=ab-ba;
		if (b%2==0 && a%2==0 && a>0 && b>0) {
			ans++;
		}
	}
	cout << ans;

	return 0;
}
