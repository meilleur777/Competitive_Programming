#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(1e3+1, 0);
	rep(i, n) {
		int l, h;
		cin >> l >> h;
		a[l]=h;
	}
	int index=max_element(a.begin(), a.end())-a.begin();
	int ans=0;
	int now=0;
	for (int i=1; i<index; i++) {
		if (now<a[i]) {
			now=a[i];
		}
		ans+=now;
	}
	now=0;
	for (int i=1e3; i>=index; i--) {
		if (now<a[i]) now=a[i];
		ans+=now;
	}
	cout << ans;

	return 0;
}
