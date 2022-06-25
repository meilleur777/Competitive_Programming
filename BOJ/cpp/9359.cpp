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

	int t;
	cin >> t;
	int q=1;
	while (t--) {
		ll a, b, n;
		cin >> a >> b >> n;
		set<int> s;
		for (int i=2; i*i<=n; i++) {
			while (n%i==0) {
				s.insert(i);
				n/=i;
			}
		}
		if (n!=1) s.insert(n);
		vector<int> pfa;
		for (auto i:s) pfa.push_back(i);
		ll ans=0;
		for (int i=1; i<(1<<(int)pfa.size()); i++) {
			int cnt=0;
			ll tmp=1;
			for (int j=0; j<(int)pfa.size(); j++) {
				if (i&(1<<j)) {
					tmp*=pfa[j];
					cnt++;
				}
			}
			ll fora=(a-1)/tmp;
			ll forb=b/tmp;
			tmp=forb-fora;
			if (cnt%2==0) tmp*=-1;
			ans+=tmp;
		}	
		cout << "Case #" << q << ": " << b-a+1-ans << '\n';	
		q++;
	}

	return 0;
}
