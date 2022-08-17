#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, t;
	cin >> n >> t;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	for (int i=0; i<n; i++) {
		if (t-a[i]<0) {
			cout << i;
			return 0;
		}
		t-=a[i];
	}
	cout << n;

	return 0;
}
