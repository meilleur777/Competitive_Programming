#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string s, e;
	cin >> s >> e;
	s='!'+s;
	e='!'+e;

	int dp[2][(int)e.size()+1]={0};
	vector<vector<char>> sel((int)s.size()+1, vector<char>(((int)e.size()+4)/4));

	function<int(int, int)> read=[&](int ss, int ee) {
		char t=sel[ss][ee/4];
		int a=(t&(0x01<<(ee%4*2+1)));
		int b=(t&(0x01<<(ee%4*2)));
		int res=0;
		return (!!a)*2+(!!b);
	};
	function<void(int, int, int)> write=[&](int ss, int ee, int value) {
		if (2&value) sel[ss][ee/4]|=(0x01<<(ee%4*2+1));
		if (1&value) sel[ss][ee/4]|=(0x01<<(ee%4*2));
	};

	for (int i=0; i<(int)e.size()+1; i++) {
		dp[0][i]=i;
		write(0, i, 0);
	}
	for (int i=0; i<(int)s.size(); i++) {
		write(i, 0, 1);
	}
	for (int i=1; i<(int)s.size(); i++) {
		dp[1][0]=i;
		for (int j=1; j<(int)e.size(); j++) {
			if (s[i]==e[j]) {
				dp[1][j]=dp[0][j-1];
				write(i, j, 3);
			}
			else {
				dp[1][j]=min({dp[0][j], dp[0][j-1], dp[1][j-1]})+1;
				if (dp[1][j]==dp[0][j]+1) write(i, j, 1);
				else if (dp[1][j]==dp[0][j-1]+1) write(i, j, 2);
				else write(i, j, 0);
			}
		}
		for (int j=0; j<(int)e.size(); j++) {
			dp[0][j]=dp[1][j];
		}
	}

	function<void(int, int)> rec=[&](int ss, int ee) {
		if (!ss && !ee) return;
		switch (read(ss, ee)) {
			case 0: rec(ss, ee-1);
					cout << 'a' << ' ' << e[ee] << '\n';
					break;
			case 1: rec(ss-1, ee);
					cout << 'd' << ' ' << s[ss] << '\n';
					break;
			case 2: rec(ss-1, ee-1);
					cout << 'm' << ' ' << e[ee] << '\n';
					break;
			case 3: rec(ss-1, ee-1);
					cout << 'c' << ' ' << e[ee] << '\n';
		}
	};
	rec((int)s.size()-1, (int)e.size()-1);

	return 0;
}
