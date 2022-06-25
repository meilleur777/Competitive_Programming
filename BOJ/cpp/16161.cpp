#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	if (n==1) {
		cout << 1;
		return 0;
	}

	vector<bool> v(n, false);
	v[0]=a[0]<a[1];
	for (int i=1; i<n-1; i++) {
		v[i]=(a[i-1]>a[i] && a[i]<a[i+1]) || (a[i-1]==a[i] && a[i]<a[i+1]) || (a[i-1]>a[i] && a[i]==a[i+1]);
	}	
	v[n-1]=a[n-2]>a[n-1];

	int ans=1;
	rep(i, n-1) {
		if (a[i]==a[i+1]) ans=2;
	}

	vector<int> q;
	for (int i=0; i<n; i++) {
		if (v[i] && !q.empty()) {
			q.push_back(a[i]);

			int left=max_element(q.begin(), q.end())-q.begin();
			int right=left;
			if (left+1<q.size() && q[left+1]==q[left]) {
				right++;
			}
			int now=0;
			if (left==right) {
				now=1;
				left--;
				right++;
			}
			while (0<=left && right<q.size() && q[left]==q[right]) {
				now+=2;
				left--;
				right++;
			}
			ans=max(ans, now);
			q.clear();
		}
		q.push_back(a[i]);
	}
	cout << ans;

	return 0;
}
