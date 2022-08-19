	#include <bits/stdc++.h>
	#define rep(i, n) for(int i=0; i<(n); i++)
	using namespace std;

	typedef long long ll;
	typedef pair<int, int> intp;

	int main() {
		ios_base::sync_with_stdio(false); cin.tie(0);
		
		int n, x;
		cin >> n >> x;
		vector<intp> v(n);
		rep(i, n) cin >> v[i].first >> v[i].second;
		ll sum=0;
		rep(i, n) {
			sum+=v[i].second;
			x-=1000;
		}
		sort(v.begin(), v.end(), [&](const intp& p, const intp& q) {
			return p.first-p.second>q.first-q.second;
		});

		int ptr=0;
		ll ans=sum;
		while (ptr<n && v[ptr].first-v[ptr].second>0 && x>=4000) {
			x-=4000;
			sum+=v[ptr].first-v[ptr].second;
			ptr++;
			ans=max(ans, sum);
		}
		cout << ans;


		return 0;
	}
