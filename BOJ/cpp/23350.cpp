#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	deque<intp> v;
	vector<int> cnt(m+1, 0);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, b});
		cnt[a]++;
	}
	int now=m;
	int ans=0;
	vector<stack<int>> a(m+1);
	while (!v.empty()) {
		while (now>=1 && !cnt[now]) now--;
		if (now==0) break;
		while (cnt[now]) {
			intp t=v.front();
			v.pop_front();
			if (t.first!=now) {
				v.push_back(t);
				ans+=t.second;
			}
			else {
				stack<int> memo;
				while (!a[now].empty() && a[now].top()<t.second) {
					memo.push(a[now].top());
					ans+=a[now].top();
					a[now].pop();
				}
				a[now].push(t.second);
				ans+=t.second;
				while (!memo.empty()) {
					a[now].push(memo.top());
					ans+=memo.top();
					memo.pop();
				}
				cnt[now]--;
			}
		}
	}
	cout << ans;

	return 0;
}
