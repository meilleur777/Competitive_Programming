#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	int ans=1e9;
	int left=*max_element(a.begin(), a.end()), right=1e9;
	while (left<=right) {
		int mid=(left+right)/2;
		int cnt=1;
		int now=0;
		for (int i=0; i<n; i++) {
			if (now+a[i]>mid) {
				now=a[i];
				cnt++;
			}
			else now+=a[i];
		}
		if (cnt<=m) {
			right=mid-1;
			ans=min(ans, mid);
		}
		else {
			left=mid+1;
		}
	}
	cout << ans;

	return 0;
}
