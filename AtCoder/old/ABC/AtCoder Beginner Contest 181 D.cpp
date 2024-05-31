#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<int> cnt(10, 0);

void sol(string now) {
	if (now.size()==3) {
		int n=stoi(now);
		if (n%8==0) {
			cout << "Yes";
			exit(0);
		}
		return;
	}
	for (int i=1; i<10; i++) {
		if (cnt[i]>0) {
			cnt[i]--;
			sol(now+char(i+'0'));
			cnt[i]++;
		}
	}
}

int main() {
	init_code();

	string s;
	cin >> s;
	if (s.size()<3) {
		sort(s.begin(), s.end());
		do {
			int now=stoi(s);
			if (now%8==0) {
				cout << "Yes";
				return 0;
			} 
		} while (next_permutation(s.begin(), s.end()));
		cout << "No";
	}
	else {
		for (auto i:s) {
			cnt[i-'0']++;
		}
		sol("");
		cout << "No";
	}

	return 0;
}
