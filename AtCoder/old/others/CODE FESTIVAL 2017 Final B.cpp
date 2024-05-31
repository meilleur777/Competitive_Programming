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
	vector<int> cnt(3, 0);
	rep(i, s.size()) cnt[s[i]-'a']++;
	if (abs(cnt[0]-cnt[1])<2 && abs(cnt[1]-cnt[2])<2 && abs(cnt[2]-cnt[0])<2) cout << "YES";
	else cout << "NO";

	return 0;
}
