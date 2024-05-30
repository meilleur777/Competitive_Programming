#include <bits/stdc++.h>
using namespace std;

long long getSum(const vector<long long>& segmentTree, int node, int left, int right, int begin, int end) {
    if (end<left || right<begin) return 0;
    if (begin<=left && right<=end) return segmentTree[node];

    int mid=(left+right)/2;
    long long leftSum=getSum(segmentTree, node*2+1, left, mid, begin, end);
    long long rightSum=getSum(segmentTree, node*2+2, mid+1, right, begin, end);

    return leftSum+rightSum;
}

void update(vector<long long>& segmentTree, int node, int left, int right, int index, long long diff) {
    if (index<left || right<index) return;
    segmentTree[node]+=diff;
    if (left>=right) return;

    int mid=(left+right)/2;
    update(segmentTree, node*2+1, left, mid, index, diff);
    update(segmentTree, node*2+2, mid+1, right, index, diff);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    int treeHeight=(int)ceil(log2(n));
    int treeSize=(1<<(treeHeight+1));
    vector<long long> segmentTree(treeSize, 0);

    vector<long long> a(n, 0);

    while (m--) {
        int ope, i, j;
        cin >> ope >> i >> j;

        if (ope==0) {
            if (i>j) swap(i, j);
            cout << getSum(segmentTree, 0, 0, n-1, i-1, j-1) << '\n';
        }
        else if (ope==1) {
            long long diff=j-a[i-1];
            a[i-1]+=diff;
            update(segmentTree, 0, 0, n-1, i-1, diff);
        }
    }

    return 0;
}
