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

	string s[3];
	set<int> m;
	m.insert('B'-'A');
	m.insert('R'-'A');
	m.insert('G'-'A');
	m.insert('H'-'A');
	rep(i, 3) {
		string s;
		cin >> s;
		m.erase(m.find(s[1]-'A'));
	}
	cout << 'A' << char(*m.begin()+'A') << 'C';

	return 0;
}
