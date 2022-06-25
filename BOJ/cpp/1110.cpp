#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	int t=n;
	int cnt=0;	
	do {
		t=(t%10+t/10)%10+t%10*10;
		cnt++;
	} while (t!=n);
	cout << cnt;

	return 0;
}
