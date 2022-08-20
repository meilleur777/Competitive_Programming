#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	vector<intp> a(8);
	rep(i, 8) {
		cin >> a[i].first;
		a[i].second=i+1;
	}
	sort(a.begin(), a.end(), greater<intp>());
	int sum=0;
	set<int> st;
	rep(i, 5) {
		sum+=a[i].first;
		st.insert(a[i].second);
	}
	cout << sum << '\n';
	int cnt=5;
	for (auto i:st) {
		cnt--;
		cout << i << ' ';
		if (!cnt) break;
	}

	return 0;
}
