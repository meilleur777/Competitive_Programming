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
	vector<int> cnt(n, 0);
	rep(i, n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cnt[a]++, cnt[b]++;
	}
	rep(i, n) {
		if (cnt[i]==n-1) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";

	return 0;
}
