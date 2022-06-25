#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int k;
	cin >> k;
	set<intp> st;
	vector<int> sty, stx;
	int y=0, x=0;
	vector<int> dy({0, 0, 1, -1}), dx({1, -1, 0, 0});
	st.insert({0, 0});
	sty.push_back(0);
	stx.push_back(0);
	rep(i, 6) {
		int a, b;
		cin >> a >> b;
		a--;
		y+=dy[a]*b;
		x+=dx[a]*b;
		st.insert({y, x});
		sty.push_back(y);
		stx.push_back(x);
	}
	sort(sty.begin(), sty.end());
	sort(stx.begin(), stx.end());
	sty.erase(unique(sty.begin(), sty.end()), sty.end());
	stx.erase(unique(stx.begin(), stx.end()), stx.end());
	int ans=0;
	for (auto [a, b]:st) {
		if (sty[1]==a || stx[1]==b) continue;
		ans+=abs((a-sty[1])*(b-stx[1]));
	}
	cout << ans*k;

	return 0;
}
