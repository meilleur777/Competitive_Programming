#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		vector<int> pos(n);
		rep(i, n) pos[i]=n-i-1;
		int now=n;

		int height=ceil(log2(n+m))+1;
		int size=(1<<height);
		vector<int> tree(size, 0);
		function<int(int, int, int, int, int)> sum=[&](int node, int start, int end, int left, int right) {
			if (right<start || end<left) return 0;
			if (left<=start && end<=right) return tree[node];
			int mid=(start+end)/2;
			int leftsum=sum(node*2+1, start, mid, left, right);
			int rightsum=sum(node*2+2, mid+1, end, left, right);
			return leftsum+rightsum;
		};
		function<void(int, int, int, int, int)> update=[&](int node, int start, int end, int index, int value) {
			if (index<start || end<index) return;
			if (start==end && start==index) {
				tree[node]=value;
				return;
			}
			int mid=(start+end)/2;
			update(node*2+1, start, mid, index, value);
			update(node*2+2, mid+1, end, index, value);
			tree[node]=tree[node*2+1]+tree[node*2+2];
		};

		rep(i, n) update(0, 0, n+m-1, i, 1);
		rep(i, m) {
			int a;
			cin >> a;
			a--;
			cout << sum(0, 0, n+m-1, pos[a]+1, n+m-1) << ' ';
			update(0, 0, n+m-1, pos[a], 0);
			pos[a]=now;
			update(0, 0, n+m-1, pos[a], 1);
			now++;
		}
		cout << '\n';
	}

	return 0;
}
