#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	map<string, int> mp;
	while (n--) {
		string s;
		cin >> s;
		mp[s]++;
	}

	int mx=(*max_element(mp.begin(), mp.end(), [](const pair<string, int>& p, const pair<string, int>& q) {
		return p.second<q.second;
	})).second;
	for (auto i:mp) {
		if (i.second==mx) {
			cout << i.first;
			return 0;
		}
	}

	return 0;
}
