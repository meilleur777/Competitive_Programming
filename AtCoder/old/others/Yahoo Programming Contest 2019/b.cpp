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

	vector<int> cnt(4, 0);
	rep(i, 6) {
		int a;
		cin >> a;
		cnt[a-1]++;
	}
	sort(cnt.begin(), cnt.end());
	vector<int> a({1, 1, 2, 2});
	if (cnt==a) cout << "YES";
	else cout << "NO";

	return 0;
}
