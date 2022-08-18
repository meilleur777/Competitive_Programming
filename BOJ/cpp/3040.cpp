#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int sum=0;
	vector<int> a(9);
	rep(i, 9) {
		cin >> a[i];
		sum+=a[i];
	}
	rep(i, 9) rep(j, 9) {
		if (i==j) continue;
		if (sum-a[i]-a[j]==100) {
			rep(k, 9) {
				if (k==i || k==j) continue;
				cout << a[k] << '\n';
			}
			return 0;
		}
	}

	return 0;
}
