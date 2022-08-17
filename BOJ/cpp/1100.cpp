#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
			
	int ans=0;
	for (int i=0; i<8; i++) {
		string s;
		cin >> s;
		for (int j=0; j<8; j++) {
			if ((i+j)%2) continue;
			ans+=s[j]=='F';
		}
	}
	cout << ans;

	return 0;
}
