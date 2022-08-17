#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	string a, b;
	cin >> a >> b;
	int ans=-1;
	for (int i=0; i<=(int)b.size()-(int)a.size(); i++) {
		int cnt=0;
		for (int j=0; j<(int)a.size(); j++) {
			cnt+=b[j+i]==a[j];
		}
		ans=max(ans, cnt);
	}
	cout << (int)a.size()-ans;

	return 0;
}
