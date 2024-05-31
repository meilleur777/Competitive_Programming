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

	string s;
	cin >> s;
	bool flag=true;
	if (s[0]!='A') flag=false;
	int cnt=0, ind;
	for (int i=2; i<s.size()-1; i++) {
		if (s[i]=='C') {
			cnt++;
			ind=i;
		}
	}
	if (cnt!=1) flag=false;
	for (int i=1; i<s.size(); i++) {
		if (i==ind) continue;
		if (!islower(s[i])) flag=false;
	}
	if (flag) cout << "AC";
	else cout << "WA";

	return 0;
}
