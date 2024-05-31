#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int mod=1e9+7;
const int INF=0x3F3F3F3F;

int n;
string s;
vector<string> dp;

ll power(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=power(a, b/2);
	tmp=tmp*tmp%mod;
	if (b%2) return tmp*a%mod;
	return tmp;
}

char win(char a, char b) {
	if (a==b) return a;
	if ((a=='R' && b=='S') || (a=='P' && b=='R') || (a=='S' && b=='P')) return a;
	return b;
}

// return winner of kth tournament
char sol(int now, int k) {
	if (k==0) {
		return s[now];
	}
	char& ret=dp[now][k];
	if (ret!='e') return ret;
	char a=sol(now, k-1);
	char b=sol((now+power(2, k-1))%n, k-1);
	return ret=win(a, b);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k;
	cin >> n >> k >> s;
	mod=n;
	dp=vector<string>(n, string(k+1, 'e'));
	cout << sol(0, k);

	return 0;
}
