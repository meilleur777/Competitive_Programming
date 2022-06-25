#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<vector<int>> a(9, vector<int>(n));
	rep(i, n) rep(j, 9) cin >> a[j][i];
	vector<int> b;
	rep(i, 9) b.push_back(i);
	int ans=0;
	do {
		if (b[3]) continue;
		int res=0;
		int now=0;	
		rep(i, n) {
			int ouc=0;
			deque<int> dq;
			while (true) {
				auto ww=[&](int ee) {
					for (auto& q:dq) q+=ee;
					dq.push_back(ee);
					while (!dq.empty() && dq.front()>3) {
						dq.pop_front();
						res++;
					}
				};
				if (a[b[now]][i]==0) {
					ouc++;
				}
				else ww(a[b[now]][i]);
				now=(now+1)%9;
				if (ouc==3) break;
			}
		}
		ans=max(ans, res);
	} while (next_permutation(b.begin(), b.end()));
	cout << ans;

	return 0;
}
