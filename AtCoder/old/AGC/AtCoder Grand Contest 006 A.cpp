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

int main() {
	init_code();

	int N;
	string s, t;
	cin >> N >> s >> t;
	for (int i=0; i<s.size(); i++) {
		if (s.substr(i, N)==t.substr(0, N)) {
			string tmp=string(s.begin(), s.begin()+i)+t;
			cout << tmp.size();
			return 0;
		}
		N--;
	}
	cout << s.size()+t.size();

	return 0;
}
