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

string s;
int ans=0;

void sol(string now) {
	if (now.size()==4) {
		vector<bool> chk(10, false);
		rep(i, 4) {
			chk[now[i]-'0']=true;
		}
		rep(i, 10) {
			if (s[i]=='o') if (!chk[i]) return;
			if (s[i]=='x') if (chk[i]) return;
		}
		ans++;
		return;
	}
	rep(i, 10) {
		sol(now+char(i+'0'));
	}
}

int main() {
	init_code();

	cin >> s;
	sol("");
	cout << ans;

	return 0;
}
