#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	map<string, int> mp;
	for (int i=0; i<n; i++) {
		string a;
		cin >> a;
		if ((int)a.size()>=m)
		mp[a]++;
	}

	vector<pair<string, int>> v;
	for (auto p:mp) v.push_back(p);
	sort(v.begin(), v.end(), [&](const pair<string, int> &p, const pair<string, int> &q) {
		if (p.second==q.second) {
			if (p.first.size()==q.first.size()) {
				return p.first<q.first;
			}
			return p.first.size()>q.first.size();
		}
		return p.second>q.second;
	});
	for (auto p:v) {
		cout << p.first << '\n';
	}

	return 0;
}
