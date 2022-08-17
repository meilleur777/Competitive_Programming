#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	string s;
	cin >> n >> s;

	vector<ll> cnt1(n, 0), cnt2(n, 0);
	cnt1[0]=s[0]=='W';
	for (int i=1; i<n; i++) {
		cnt1[i]=cnt1[i-1]+(s[i]=='W');
	}

	ll mod=1e9+7;
	vector<ll> cal(n, 0);
	cnt2[n-1]=s[n-1]=='E';
	cal[n-1]=s[n-1]=='E'?2:1;
	for (int i=n-2; i>=0; i--) {
		cnt2[i]=cnt2[i+1]+(s[i]=='E');
		cal[i]=cal[i+1]*(s[i]=='E'?2LL:1LL);
		cal[i]%=mod;
	}

	ll ans=0;
	for (int i=1; i<n-1; i++) {
		if (s[i]!='H') continue;
		ans+=((cnt1[i-1]%mod)*(cal[i]-1-cnt2[i+1]+mod)%mod)%mod;
		ans%=mod;
	}
	cout << ans;

	return 0;
}
