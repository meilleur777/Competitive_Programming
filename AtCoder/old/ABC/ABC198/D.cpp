#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); i++)
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

string s[3];
vector<int> can(26, -1);
vector<int> need;
vector<bool> sel(10, false);

void solve(int now) {
	if (now==need.size()) {
		bool flag=true;
		string t[3]={s[0], s[1], s[2]};
		for (int i=0; i<3; i++) {
			if (can[t[i][0]-'a']==0) {
				flag=false;
				break;
			}
			for (int j=0; j<t[i].size(); j++) {
				t[i][j]=char(can[t[i][j]-'a']+'0');
			}
		}
		if (!flag) {
			return;
		}
		ll N[3];
		rep(i, 3) {
			N[i]=stoll(t[i]);
		}
		if (N[0]+N[1]==N[2]) {
			rep(i, 3) {
				cout << N[i] << '\n';
			}
			exit(0);
		}
		return;
	}
	for (int i=0; i<10; i++) {
		if (sel[i]==false) {
			sel[i]=true;
			can[need[now]]=i;
			solve(now+1);
			sel[i]=false;
		}
	}
}

int main() {
	init_code();

	rep(i, 3) cin >> s[i];
	vector<int> cnt(26, 0);
	rep(i, 3) {	
		for (auto j : s[i]) {
			cnt[j-'a']++;
		}
	}
	for (int i=0; i<26; i++) {
		if (cnt[i]>0) {
			need.push_back(i);
		}
	}
	//cout << need.size() << '\n';
	if (need.size()>10) {
		cout << "UNSOLVABLE";
		return 0;
	}
	solve(0);
	cout << "UNSOLVABLE";

	return 0;
}
