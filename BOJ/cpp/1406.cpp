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
	int m;
	cin >> s >> m;
	list<char> l(s.begin(), s.end());
	list<char>::iterator it=l.end();
	while (m--) {
		char o;
		cin >> o;
		if (o=='L') { 
			if (it!=l.begin()) it--;
		}
		else if (o=='D') {
			list<char>::iterator tt=l.end();
			if (it!=tt) it++;
		}
		else if (o=='B') {
			if (it==l.begin()) continue;
			list<char>::iterator tt=it;
			it--;
			l.erase(it);
			it=tt;
		}
		else {
			cin >> o;
			l.insert(it, o);
		}
	}
	for (auto i:l) {
		cout << i;
	}

	return 0;
}
