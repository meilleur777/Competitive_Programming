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

	string s;
	cin >> s;
	int memo=s.size();
	while (s.size()<memo*3) {
		if (s.size()%2) {
			string t=string(s.begin(), s.begin()+s.size()/2);
			reverse(t.begin(), t.end());
			if (t==string(s.begin()+s.size()/2+1, s.end())) {
				cout << "Yes";
				return 0;
			}
		}
		else {
			string t=string(s.begin(), s.begin()+s.size()/2);
			reverse(t.begin(), t.end());
			if (t==string(s.begin()+s.size()/2, s.end())) {
				cout << "Yes";
				return 0;
			}	
		}
		s='0'+s;
	}	
	cout << "No";

	return 0;
}
