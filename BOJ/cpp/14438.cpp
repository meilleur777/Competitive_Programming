#include <bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;

int getMin(const vector<int>& tree, int node, int left, int right, int begin, int end) {
    if (end<left || right<begin) return inf;
    if (begin<=left && right<=end) return tree[node];

    int mid=(left+right)/2;
    int leftMin=getMin(tree, node*2+1, left, mid, begin, end);
    int rightMin=getMin(tree, node*2+2, mid+1, right, begin, end);

    return min(leftMin, rightMin);
}

void update(vector<int>& tree, int node, int left, int right, int index, int value) {
    if (index<left || right<index) return;
    if (index==left && index==right) {
        tree[node]=value;
        return;
    }

    int mid=(left+right)/2;
    update(tree, node*2+1, left, mid, index, value);
    update(tree, node*2+2, mid+1, right, index, value);
    tree[node]=min(tree[node*2+1], tree[node*2+2]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    int m;
    cin >> m;

    int treeHeight=ceil(log2(n));
    int treeSize=(1<<(treeHeight+1));
    vector<int> tree(treeSize, inf);
    for (int i=0; i<n; i++) update(tree, 0, 0, n-1, i, a[i]);

    while (m--) {
        int ope, i, j;
        cin >> ope >> i >> j;

        if (ope==1) {
            i--;
            a[i]=j;
            update(tree, 0, 0, n-1, i, j);
        }
        else if (ope==2) {
            i--, j--;
            cout << getMin(tree, 0, 0, n-1, i, j) << '\n';
        }
    }

    return 0;
}
