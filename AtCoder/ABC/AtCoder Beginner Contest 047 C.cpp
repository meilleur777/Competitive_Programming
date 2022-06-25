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
	vector<int> clu;
	int row=1;
	char memo=s[0];
	for (int i=1; i<s.size(); i++) {
		if (memo!=s[i]) {
			clu.push_back(row);
			row=1;
			memo=s[i];
		}
		else row++;
	}
	clu.push_back(row);
	cout << clu.size()-1;

	return 0;
}
