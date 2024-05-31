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

int main() {
	init_code();

	string S;
	cin >> S;
	int ans=INF;
	for (int i=0; i+3<=S.size(); i++) {
		string t(S.begin()+i, S.begin()+i+3);
		int c=stoi(t);
		ans=min(ans, abs(753-c));	
	}
	cout << ans;

	return 0;
}
