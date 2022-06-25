#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	set<string> st;
	rep(i, n) {
		string k;
		cin >> k;
		st.insert(k);
	}
	int ans=0;
	rep(i, m) {
		string k;
		cin >> k;
		ans+=st.find(k)!=st.end();
	}
	cout << ans;

	return 0;
}
