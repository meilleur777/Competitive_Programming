#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, s;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	cin >> s;

	int cnt=0;
	while (true) {
		int index=cnt;
		for (int i=cnt+1; i<n && i-cnt<=s; i++) {
			if (a[i]>a[index]) {
				index=i;
			}
		}
		if (index==cnt) {
			cnt++;
			if (cnt>=n-1) break;
			continue;
		}	
		for (int i=index; i>cnt; i--) {
			int t=a[i];
			a[i]=a[i-1];
			a[i-1]=t;
		}
		s-=index-cnt;
		if (s==0) break;
		cnt++;
		if (cnt>=n-1) break;
	}

	for (auto i:a) cout << i << ' ';

	return 0;
}
