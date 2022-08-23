#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	int ans=0;
	if (a<0) {
		ans+=(-a)*c;
		a=0;
	}
	if (a==0) {
		ans+=d;
	}
	ans+=(b-a)*e;
	cout << ans;

	return 0;
}
