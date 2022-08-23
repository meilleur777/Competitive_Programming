#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<intp> a(2), b(2);
	rep(i, 2) cin >> a[i].first >> a[i].second;
	rep(i, 2) cin >> b[i].first >> b[i].second;
	int tmp=max(max(a[1].first, b[1].first)-min(a[0].first, b[0].first), max(a[1].second, b[1].second)-min(a[0].second, b[0].second));
	cout << tmp*tmp;

	return 0;
}
