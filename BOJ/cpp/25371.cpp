#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, k;
	cin >> n >> k;

	vector<int> a;
	while (n) {
		a.push_back(n%k);
		n/=k;
	}
	reverse(a.begin(), a.end());

	ll tmp=0;
	string now="";
	for (auto c:a) {
		if (!c) {
			if (!now.empty()) {
				tmp+=stol(now);
				now="";
			}
		}
		else {
			now.push_back(c+'0');
		}
	}
	if (!now.empty()) tmp+=stol(now);

	vector<int> ans;
	while (tmp) {
		ans.push_back(tmp%k);
		tmp/=k;
	}
	if (ans.empty()) cout << 0;
	else {
		reverse(ans.begin(), ans.end());
		for (auto i:ans) cout << i;
	}

	return 0;
}
