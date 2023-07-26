#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<pair<int, int>> coor(n);
		vector<int> cx(n), cy(n), tx, ty;
		for (int i=0; i<n; i++) {
			cin >> coor[i].first >> coor[i].second;
			cx[i]=coor[i].first;
			cy[i]=coor[i].second;
		}
		sort(cx.begin(), cx.end());
        sort(cy.begin(), cy.end());
        cx.resize(unique(cx.begin(), cx.end())-cx.begin());
        cy.resize(unique(cy.begin(), cy.end())-cy.begin());
        int coordsize=(int)cx.size();
        for (int i=0; i<n; i++) {
        	coor[i].first=(int)(lower_bound(cx.begin(), cx.end(), coor[i].first)-cx.begin());
        	coor[i].second=(int)(lower_bound(cy.begin(), cy.end(), coor[i].second)-cy.begin());
        }
        sort(coor.begin(), coor.end(), [&](const pair<int, int>& p, const pair<int, int>& q) {
        	if (p.second==q.second) {
        		return p.first>q.first;
        	}
        	return p.second<q.second;
        });

        int treeheight=(int)ceil(log2(coordsize));
		int treesize=(1<<(treeheight+1))-1;
        vector<int> tree(treesize, 0);
        function<int(int, int, int, int, int)> getsum=[&](int node, int left, int right, int begin, int end) {
        	if (end<left || right<begin) return 0;
        	if (begin<=left && right<=end) return tree[node];

        	int mid=(left+right)/2;
        	int leftsum=getsum(node*2+1, left, mid, begin, end);
        	int rightsum=getsum(node*2+2, mid+1, right, begin, end);
        	return leftsum+rightsum;
        };
        function<void(int, int, int, int, int)> update=[&](int node, int left, int right, int index, int value) {
        	if (index<left || right<index) return;
        	tree[node]+=value;
        	if (left!=right) {
        		int mid=(left+right)/2;
        		update(node*2+1, left, mid, index, value);
        		update(node*2+2, mid+1, right, index, value);
        	}
        };

        ll ans=0;
        for (auto c:coor) {
        	int x=c.first;
        	int y=c.second;

        	ans+=getsum(0, 0, coordsize-1, x, coordsize-1);
        	update(0, 0, coordsize-1, x, 1);
        }
        cout << ans << '\n';
	}

	return 0;
}
