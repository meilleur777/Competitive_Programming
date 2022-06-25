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
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	h.push_back(0);
	int ans=0;
	stack<int> s;
	for (int i=0; i<n+1; i++) {
		while (!s.empty() && h[s.top()]>h[i]) {
			int w, tmp=s.top();
			s.pop();
			if (s.empty()) w=i;
			else w=i-s.top()-1;
			ans=max(ans, h[tmp]*w);
		}	
		s.push(i);
	}
	cout << ans;

	return 0;
}
