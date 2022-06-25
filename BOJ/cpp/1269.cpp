#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b, c, ans=0;
	cin >> a >> b;
	set<int> st;
	rep(i, a) {
		cin >> c;
		st.insert(c);
	}
	rep(i, b) {
		cin >> c;
		ans+=st.find(c)!=st.end();
	}
	cout << a+b-2*ans;

	return 0;
}
