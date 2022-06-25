#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	vector<int> a(n); 
	vector<intp> cnt(8001, {0, 0});
	rep(i, 8001) cnt[i].second=i-4000;
	int sum=0;
	rep(i, n) {
		cin >> a[i];
		sum+=a[i];
		cnt[a[i]+4000].first++;
	}
	sort(a.begin(), a.end());
	sort(cnt.begin(), cnt.end(), [&](intp a, intp b){
		if (a.first==b.first) return a.second>b.second;
		return a.first<b.first;
	});
	cout << sum/abs(sum)*(abs(sum)+n/2)/n << '\n' << a[n/2] << '\n';
	if (cnt[8000].first==cnt[7999].first) cout << cnt[7999].second << '\n';
	else cout << cnt.back().second << '\n';
	cout << *max_element(a.begin(), a.end())-*min_element(a.begin(), a.end());

	return 0;
}
