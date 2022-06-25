#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--)	{
		int n, m;
		cin >> n >> m;
		vector<vector<int>> v(n);
		vector<int> c(n);
		rep(i, n) {
			int k;
			cin >> k;
			rep(j, k) {
				int a;
				cin >> a;
				v[i].push_back(a-1);
			}
			cin >> c[i];
		}
		vector<int> hav(m);
		rep(i, m) cin >> hav[i];
		vector<int> w(n);
		rep(i, n) w[i]=i;
		sort(w.begin(), w.end(), [&](int a, int b) {
			return c[a]>c[b];
		});
		int ans=0;
		int INF=0x3f3f3f3f;
		rep(i, n) {
			int mn=INF;
			for (auto j:v[w[i]]) {
				mn=min(mn, hav[j]);
			}
			ans+=mn*c[w[i]];
			for (auto j:v[w[i]]) {
				hav[j]-=mn;
			}
		}
		cout << ans << '\n';
	}

	return 0;
}
