#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<intp> v(n);
	rep(i, n) cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), [](intp a, intp b) {
		return a.second>b.second;
	});
	int now=v.front().second;
	for (auto i:v) {
		now=min(now, i.second);
		now-=i.first;
	}
	cout << max(now, -1);

	return 0;
}
