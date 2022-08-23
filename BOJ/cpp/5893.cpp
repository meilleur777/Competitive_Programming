#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string n;
	cin >> n;
	reverse(n.begin(), n.end());
	string t=n;
	n="0000"+n+"0";
	int nxt=0;
	for (int i=0; i<(int)n.size(); i++) {
		int forn=0, fort=0;
		if (i<(int)n.size()) forn=n[i]-'0';
		if (i<(int)t.size()) fort=t[i]-'0';
		int tmp=0;
		if (forn+fort+nxt>1) {
			tmp=(forn+fort+nxt)%2;
			nxt=1;
		}
		else {
			tmp=forn+fort+nxt;
			nxt=0;
		}
		n[i]=tmp+'0';
	}
	while (n.back()=='0') n.pop_back();
	reverse(n.begin(), n.end());
	cout << n;

	return 0;
}
