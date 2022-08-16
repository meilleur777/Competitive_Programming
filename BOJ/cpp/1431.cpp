#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end(), [&](string& p, string& q) {
		if ((int)p.size()==(int)q.size()) {
			int pp=0, qq=0;
			for (auto c:p) {
				if (c>='0' && c<='9') pp+=c-'0';
			}
			for (auto c:q) {
				if (c>='0' && c<='9') qq+=c-'0';
			}
			if (pp==qq) {
				return p<q;
			}
			return pp<qq;
		}
		return p.size()<q.size();
	});
	for (auto i:a) cout << i << '\n';

	return 0;
}
