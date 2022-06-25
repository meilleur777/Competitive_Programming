#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

ll N;
ll ans=0;

void solve(string s) {
	ll tmp=stoll(s);
	if (tmp<=N) {
		if (s.find('3')!=string::npos && s.find('5')!=string::npos && s.find('7')!=string::npos) {
			ans++;
		}
	}
	else return;
	solve(s+'3');
	solve(s+'5');
	solve(s+'7');
}

int main() {
	init_code();

	cin >> N;
	solve("3");
	solve("5");
	solve("7");
	cout << ans;

	return 0;
}
