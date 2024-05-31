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

 int mod=1e9+7;
const int INF=0x3F3F3F3F;

void inv(char& a) {
	if (a=='0') a='1';
	else a='0';
}

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
	string x;
	cin >> n >> x;
	int now=0;
	int cnt=0;
	for (int i=0; i<n; i++) {
		cnt+=x[i]-'0';
	}
	int psum=0, msum=0;
	mod=cnt+1;
	for (int i=0; i<n; i++) {
		psum+=(x[i]-'0')*power(2, n-i-1);
		psum%=mod;
	}	
	mod=max(1, cnt-1);
	for (int i=0; i<n; i++) {
		msum+=(x[i]-'0')*power(2, n-i-1);
		msum%=mod;
	}	
	for (int i=0; i<n; i++) {
		int ans=1;
		if (x[i]=='1') {
			if (cnt==1) {
				cout << 0 << '\n';
				continue;
			}
			mod=max(1, cnt-1);
			int tmp=msum;
			tmp-=power(2, n-i-1);
			tmp=(tmp+mod)%mod;
			while (true) {
				tmp%=mod;
				if (tmp==0) break;
				mod=__builtin_popcount(tmp);
				ans++;
			}
		}
		else {
			mod=cnt+1;
			int tmp=psum;
			tmp+=power(2, n-i-1);
			tmp=(tmp+mod)%mod;
			while (true) {
				tmp%=mod;
				if (tmp==0) break;
				mod=__builtin_popcount(tmp);
				ans++;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
