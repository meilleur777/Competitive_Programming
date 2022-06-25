#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> cnt(1e5+1, 0);
	rep(i, n) {
		int a;
		cin >> a;
		cnt[a]++;
	}
	int mn=0;
	int mx=0;
	for (int i=1; i<=1e5; i++) {
		if (cnt[i]>0) {
			mn=i;
			break;
		}
	}
	for (int i=1e5; i>=1; i--) {
		if (cnt[i]>0) {
			mx=i;
			break;
		}
	}
	if (mx==mn) {
		cout << -1;
		return 0;
	}
	cnt[mn+1]-=cnt[mn]-1;
	cnt[mn]=1;
	cnt[mx-1]-=cnt[mx]-1;
	cnt[mx]=1;
	if (mx-mn+1>2) {
		for (int i=mn+1; i<=mx-2; i++) {
			if (cnt[i]<2)  {
				cout << -1;
				return 0;
			}
			cnt[i+1]-=cnt[i]-2;
			cnt[i]=2;
		}
		if (cnt[mx-1]!=2) {
			cout << -1;
			return 0;
		}
	}
	if (cnt[mn]==1 && cnt[mx]==1) cout << 1;
	else cout << -1;
 
	return 0;
}
