#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

ll power(ll a, ll b) {
	ll ret=1;
	while (b) {
		if (b%2) ret*=a;
		a*=a;
		b/=2;
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	int cnt=1;
	while (true) {
		ll tmp=9*power(10, cnt-1)*cnt;
		if (k<=tmp) break;
		k-=tmp;
		cnt++;
	}

	ll tmp=power(10, cnt-1)+(k-1)/cnt;
	if (tmp>n) cout << -1;
	else {
		string t=to_string(tmp);
		cout << t[(k-1)%cnt];
	}

	return 0;
}
