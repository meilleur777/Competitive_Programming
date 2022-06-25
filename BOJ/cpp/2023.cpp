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

int n;
deque<string> dq;
vector<bool> ispri({false, false, true, true, false, true, false, true, false, false});

void solve(int now) {
	if (now==n+1) {
		for (auto i:dq) {
			cout << i << '\n';
		}
		return;
	}	
	while (dq.front().size()!=now) {
		string t=dq.front();
		dq.pop_front();
		for (int i=0; i<10; i++) {
			string s=t+char(i+'0');
			int tmp=stoi(s);
			bool flag=true;
			for (int j=2; j*j<=tmp; j++) {
				if (tmp%j==0) {
					flag=false;
					break;
				}
			}
			if (flag) {
				dq.push_back(s);
			}
		}
	}
	solve(now+1);
}

int main() {
	init_code();

	cin >> n;
	for (int i=0; i<10; i++) {
		if (ispri[i]) {
			dq.push_back(to_string(i));
		}
	}
	solve(2);

	return 0;
}
