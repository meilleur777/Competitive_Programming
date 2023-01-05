#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int k;
int cnt=0;
int ans=-1;

void merge(vector<int>& a, int sta, int mid, int ed) {
    int i=sta, j=mid+1, t=0;
    vector<int> tmp(ed-sta+1);
    while (i<=mid && j<=ed) {
        if (a[i]<=a[j]) {
            tmp[t++]=a[i++];
        }
        else {
            tmp[t++]=a[j++];
        }
    }

    while (i<=mid) {
        tmp[t++]=a[i++];
    }
    while (j<=ed) {
        tmp[t++]=a[j++];
    }
    i=sta, t=0;
    while (i<=ed) {
        a[i++]=tmp[t++];
        cnt++;
        if (k==cnt) {
            ans=a[i-1];
        }
    }
}

void merge_sort(vector<int>& a, int sta, int ed) {
    if (sta<ed) {
        int mid=(sta+ed)/2;
        merge_sort(a, sta, mid);
        merge_sort(a, mid+1, ed);
        merge(a, sta, mid, ed);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    merge_sort(a, 0, n-1);
    cout << ans;

    return 0;
}
