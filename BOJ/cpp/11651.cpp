#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<intp> a(n);
	rep(i, n) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end(), [](intp q, intp w){
		if (q.second==w.second) return q.first<w.first;
		return q.second<w.second;
	});
	rep(i, n) cout << a[i].first << ' ' << a[i].second << '\n';

	return 0;
}
