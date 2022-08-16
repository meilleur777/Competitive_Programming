#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cout << fixed;
	cout.precision(4);
		
	string s;
	int cnt=0;
	map<string, int> mp;
	while (getline(cin, s)) {
		cnt++;
		mp[s]++;
	}
	for (auto i:mp) {
		cout << i.first << ' ' << (double)100*i.second/cnt << '\n';
	}

	return 0;
}
