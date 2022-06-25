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

int main() {
	init_code();

	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	int bot=0;
	vector<bool> stb(n, false), ena(n, false);
	for (int i=0; i<n; i++) {
		string s=a[i];
		if (s[0]=='B') {
			stb[i]=true;
		}
		if (*s.rbegin()=='A') {
			ena[i]=true;
		}
		for (int j=0; j<s.size()-1; j++) {
			if (s[j]=='A' && s[j+1]=='B') {
				bot++;
			}
		}
	}
	int cntab=0, cnta=0, cntb=0;
	for (int i=0; i<n; i++) {
		if (stb[i] && ena[i]) {
			cntab++;
		}
		else if (stb[i]) cntb++;
		else if (ena[i]) cnta++;
	}
	if (cntab>0) {
		if (cnta==0 && cntb==0) {
			cout << cntab+bot-1;
		}
		else {
			cout << bot+cntab+min(cnta, cntb);
		}
	}
	else {
		cout << min(cnta, cntb)+bot;
	}

	return 0;
}
