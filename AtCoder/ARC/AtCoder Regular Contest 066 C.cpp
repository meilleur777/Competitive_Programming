#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

int main() {
	init_code();

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	bool flag=true;
	if (n%2) {
		vector<int> cnt(n, 0);
		rep(i, n) {
			if (a[i]%2) {
				flag=false;
				break;
			}
			else {
				if (cnt[a[i]]>1) {
					flag=false;
					break;
				}
				else {
					cnt[a[i]]++;
				}
			}
		}
		if (cnt[0]!=1) {
			flag=false;
		}
		if (!flag) {
			cout << 0;
		}
		else {
			ll ans=power(2, (n-1)/2);
			cout << ans;
		}
	}
	else {
		vector<int> cnt(n, 0);
		rep(i, n) {
			if (a[i]%2==0) {
				flag=false;
				break;
			}
			else {
				if (cnt[a[i]]>1) {
					flag=false;
					break;
				}
				else {
					cnt[a[i]]++;
				}
			}
		}
		if (!flag) {
			cout << 0;
		}
		else {
			ll ans=power(2, n/2);
			cout << ans;
		}
	}

	return 0;
}
