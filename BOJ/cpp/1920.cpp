#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n;
	set<int> st;
	rep(i, n) {
		int a;
		cin >> a;
		st.insert(a);
	}
	cin >> m;
	rep(i, m)  {
		int a;
		cin >> a;
		cout << (st.find(a)!=st.end()) << '\n';
	}

	return 0;
}
