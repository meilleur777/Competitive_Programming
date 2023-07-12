#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;
	set<int> st;
	while (n--) {
		int a;
		cin >> a;
		st.insert(a);
	}
	int m;
	cin >> m;
	while (m--) {
		int a;
		cin >> a;
		cout << (st.find(a)!=st.end()) << ' ';
	}

	return 0;
}
