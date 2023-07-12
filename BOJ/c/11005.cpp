#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, b;
	cin >> n >> b;
	string ans="";
	int t=b;
	while (n>0) {
		int tmp=n%t;
		if (tmp<10) {
			ans+=char(tmp+'0');
		}
		else {
			ans+=char(tmp-10+'A');
		}
		n=n/b;
	}	
	reverse(ans.begin(), ans.end());
	cout << ans;

	return 0;
}
