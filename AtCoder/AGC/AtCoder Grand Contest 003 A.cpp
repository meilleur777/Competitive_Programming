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

int main() {
	init_code();

	string s;
	cin >> s;
	string t("NWSE");
	bool flag[4]={false};
	for (int i=0; i<4; i++) {
		if (s.find(t[i])!=string::npos) flag[i]=true;
	}
	if ((flag[0] && flag[2] && !flag[1] && !flag[3]) ||
	 (!flag[0] && !flag[2] && flag[1] && flag[3]) ||
	 (flag[0] && flag[2] && flag[1] && flag[3])) {
		cout << "Yes";
	}
	else cout << "No";

	return 0;
}
