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

	int n, k;
	cin >> n >> k;
	vector<int> pos(10);
	rep(i, 10) pos[i]=i;
	rep(i, k) {
		int x;
		cin >> x;
		pos.erase(lower_bound(pos.begin(), pos.end(), x));
	}
	string s=to_string(n);
	string t;
	bool flag=false;
	for (int i=0; i<(int)s.size(); i++) {
		if (flag || pos.back()<s[i]-'0') {
			t+=char(pos[0]+'0');
		}
		else {
			for (auto j:pos) {
				if (j==s[i]-'0') {
					t+=char(j+'0');
					break;
				}
				else if (j>s[i]-'0') {
					flag=true;
					t+=char(j+'0');
					break;
				}
			}
		}
	}
	if (s>t) {
		t+=char(pos[0]+'0');
	}
	cout << t;

	return 0;
}
