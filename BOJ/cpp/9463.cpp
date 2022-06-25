#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<ll> segtree;

ll getsum(int node, int left, int right, int begin, int end) {
	if (end<left || right<begin) return 0;
	if (begin<=left && right<=end) return segtree[node];
	int mid=(left+right)/2;
	ll leftsum=getsum(node*2+1, left, mid, begin, end);
	ll rightsum=getsum(node*2+2, mid+1, right, begin, end);
	return leftsum+rightsum;
}

void update(int node, int left, int right, int index) {
	if (index<left || right<index) return;
	segtree[node]+=1;
	if (left!=right) {
		int mid=(left+right)/2;
		update(node*2+1, left, mid, index);
		update(node*2+2, mid+1, right, index);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int treeheight=ceil(log2(n))+1;
		int treesize=(1<<treeheight);
		segtree=vector<ll>(treesize, 0);

		vector<int> a(n), b(n);
		vector<intp> c(n);
		rep(i, n) {
			cin >> a[i];
			a[i]--;
		}
		rep(i, n) {
			cin >> b[i];
			b[i]--;
		}
		rep(i, n) {
			c[a[i]].first=i;
			c[b[i]].second=i;
		}
		sort(c.begin(), c.end());
		ll ans=0;
		rep(i, n) {
			ans+=getsum(0, 0, n-1, c[i].second, n-1);
			update(0, 0, n-1, c[i].second);
		}
		cout << ans << '\n';
	}

	return 0;
}
