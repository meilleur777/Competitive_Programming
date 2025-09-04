#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	vector<int> ans(10);
	for (int i=0; i<10; i++) {
		cin >> ans[i];
	}

	vector<vector<vector<vector<long long>>>> mem(10, vector<vector<vector<long long>>>(6, vector<vector<long long>>(6, vector<long long>(11, -1))));

	function<long long(int, int, int, int)> dp=[&](int now, int past, int past2, int score) {
		if (now==10) {
			if (score>=5) return 1LL;
			else return 0LL;
		}

		long long& ret=mem[now][past][past2][score];
		if (ret!=-1) return ret;
		ret=0;

		if (now==0 || now==1) {
			for (int i=1; i<=5; i++) {
				int plus=0;
				if (ans[now]==i) plus=1;

				ret+=dp(now+1, past2, i, score+plus);
			}
		}
		else {
			for (int i=1; i<=5; i++) {
				int plus=0;
				if (ans[now]==i) plus=1;

				if (past==i && past2==i) continue;

				ret+=dp(now+1, past2, i, score+plus);
			}
		}

		return ret;
	};

	cout << dp(0, 0, 0, 0);

	return 0;
}
