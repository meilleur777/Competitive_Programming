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

	int n, q;
	cin >> n >> q;
	vector<intp> a(n, {-1, -1});
	rep(i, q) {
		int k, b, c;
		cin >> k;
		if (k==1) {
			cin >> b >> c;
			b--, c--;
			a[b].second=c;
			a[c].first=b;
		}
		else if (k==2) {
			cin >> b >> c;
			b--, c--;
			a[b].second=-1;
			a[c].first=-1;
		}
		else if (k==3) {
			cin >> b;
			b--;
			int now=b;
			while (a[now].first!=-1) {
				now=a[now].first;
			}
			vector<int> ans;
			while (true) {
				ans.push_back(now);
				if (a[now].second==-1) break;
				now=a[now].second;
			}
			cout << ans.size() << ' ';
			for (auto i:ans) {
				cout << i+1 << ' ';
			}
			cout << '\n';
		}
	}

	return 0;
}
