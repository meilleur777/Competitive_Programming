#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> c(n, 0);
	vector<int> lis;
	lis.push_back(-1);
	for (int i=0; i<n; i++) {
		if (s[i]=='L') {
			if (a[i]>lis.back()) lis.push_back(a[i]);
			else lis[lower_bound(lis.begin(), lis.end(), a[i])-lis.begin()]=a[i];
		}
		c[i]+=lis.size()-1;
	}
	lis=vector<int>({-1});
	for (int i=n-1; i>=0; i--) {
		if (s[i]=='R') {
			if (a[i]>lis.back()) lis.push_back(a[i]);
			else lis[lower_bound(lis.begin(), lis.end(), a[i])-lis.begin()]=a[i];
		}
		c[i]+=lis.size()-1;	
	}
	cout << n-*max_element(c.begin(), c.end());

	return 0;
}
