#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];

	vector<int> b(n, 11);
	for (int i=1; i<=n; i++) {
		int now=0;
		while (b[now]<i) now++;
		while (a[i-1]) {
			if (b[now]>i) {
				a[i-1]--;
			}
			now++;
		}
		while (b[now]<i) now++;
		b[now]=i;
	}
	for (auto i:b) cout << i << ' ';

	return 0;
}
