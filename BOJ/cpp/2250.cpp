#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;	
	vector<intp> child(n);
	set<int> st;
	rep(i, n) {
		int a, l, r;
		cin >> a >> l >> r;
		a--, l--, r--;
		child[a]=make_pair(l, r);
		st.insert(l);
		st.insert(r);
	}
	int root=-1;
	for (int i=0; i<n; i++) {
		if (st.find(i)==st.end()) {
			root=i;
			break;
		}
	}

	vector<int> dep(n), pos(n);
	pos[root]=0;
	dep[root]=1;
	vector<vector<int>> cand(n+1);

	vector<intp> subsize(n);
	function<int(int)> eee=[&](int now) {
		int left=0;
		int right=0;
		if (child[now].first>=0) left+=eee(child[now].first);
		if (child[now].second>=0) right+=eee(child[now].second);
		subsize[now]=make_pair(left, right);
		return left+right+1;
	};
	eee(root);

	function<void(int)> sol=[&](int now) {
		int flag=0;
		if (now!=root) {
			int par=-1;
			for (int i=0; i<n; i++) {
				if (child[i].first==now) {
					flag=-1;
					par=i;
					break;
				}
				if (child[i].second==now) {
					flag=1;
					par=i;
					break;
				}
			}
			if (flag==1) {
				pos[now]=pos[par]+subsize[now].first+1;
			}
			else {
				pos[now]=pos[par]-subsize[now].second-1;
			}
			dep[now]=dep[par]+1;
		}
		cand[dep[now]].push_back(now);
		if (child[now].first>=0) sol(child[now].first);
		if (child[now].second>=0) sol(child[now].second);
	};
	sol(root);

	int mi=1;
	int mx=1;
	for (int i=2; i<=n; i++) {
		if (cand[i].size()<2) continue;
		sort(cand[i].begin(), cand[i].end(), [&](int a, int b) {
			return pos[a]<pos[b];
		});
		int t=pos[cand[i].back()]-pos[cand[i][0]]+1;
		if (mx<t) {
			mi=i;
			mx=t;
		}
	}
	cout << mi << ' ' << mx;

	return 0;
}
