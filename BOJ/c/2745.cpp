#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	string n;
	int b;
	cin >> n >> b;
	int ans=0;
	int bb=1;
	for (int i=(int)n.size()-1; i>=0; i--) {
		int t=0;
		if (isupper(n[i])) {
			t=n[i]-'A'+10;
		}
		else {
			t=n[i]-'0';
		}
		ans+=t*bb;
		bb*=b;
	}
	cout << ans;

	return 0;
}
