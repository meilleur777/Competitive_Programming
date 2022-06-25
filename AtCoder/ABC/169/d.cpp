#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll n;
	cin >> n;
	vector<int> cnt(1e6+1, 0);
	ll tmp=n;
	for (ll i=2; i*i<=n; i++) {
		while (tmp%i==0) {
			tmp/=i;
			cnt[i]++;
		}
	}
	ll k=-1;
	if (tmp!=1) k=tmp;
	int ans=(k!=-1);
	for (int i=0; i<=1e6; i++) {
		int tmp=cnt[i];
		int now=1;
		while (now*(now+1)/2<=tmp) now++;
		ans+=now-1;
	}
	cout << ans;

	return 0;
}
