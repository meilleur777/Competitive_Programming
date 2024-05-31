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

ll pow(ll a, ll b) {
	if (b==0) return 1;
	if (b==1) return a;
	ll tmp=pow(a, b/2);
	tmp*=tmp;
	if (b%2) return tmp*a;
	return tmp;
}

int main() {
	init_code();

	string s;
	ll k;
	cin >> s >> k;
	ll tmp=0;
	for (int i=0; i<s.size(); i++) {
		if (tmp+pow(s[i]-'0', 5e15-1)>=k) {
			cout << s[i]-'0';
			return 0;
		}
		tmp+=pow(s[i]-'0', 5e15-1);
	}

	return 0;
}
