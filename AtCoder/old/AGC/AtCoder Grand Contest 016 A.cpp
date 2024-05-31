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
	int ans=INT_MAX;
	for (int i=0; i<26; i++) {
		char c=char(i+'a');
		int cnt=0;
		string t=s;
		while (true) {
			bool flag=true;
			for (int j=0; j<(int)t.size(); j++) {
				if (t[j]!=c) {
					flag=false;
					break;
				}
			}
			if (flag) {
				break;
			}
			string tmp((int)t.size()-1, 'e');
			for (int j=0; j<(int)t.size()-1; j++) {
				if (t[j]==c || t[j+1]==c) {
					tmp[j]=c;
				}
				else tmp[j]=t[j];
			}
			t=tmp;
			cnt++;
		}
		ans=min(ans, cnt);
	}
	cout << ans;

	return 0;
}
