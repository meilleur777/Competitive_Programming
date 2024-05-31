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
	int k;
	cin >> s >> k;
	int n=s.size();
	for (int i=0; i<n-1; i++) {
		if (s[i]=='a') continue;
		int tmp='z'-s[i]+1;
		if (k-tmp<0) continue;
		else {
			k-=tmp;
			s[i]='a';
		}
	}
	int tmp=(int(s[n-1]-'a')+k)%26;
	s[n-1]=char(tmp+'a');
	cout << s;

	return 0;
}
