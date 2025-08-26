#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n;
	cin >> n;

	vector<pair<int, string>> v;

	for (int i=0; i<n; i++) {
		int a;
		string str;
		cin >> str >> a ;
		v.push_back(make_pair(a, str));
	}


	auto cpr=[&](pair<int, string> a, pair<int, string> b) {
		if (a.first==b.first) return a.second<b.second;
		return a.first>b.first;
	};
	sort(v.begin(), v.end(), cpr);

	cout << v.front().second;

	return 0;
}
