#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<bool> ispri(3e5+1, true);

void sieve() {
	ispri[0]=ispri[1]=false;	
	for (int i=2; i*i<=3e5+1; i++) {
		for (int j=i*2; j<=3e5+1; j+=i) {
			ispri[j]=false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n;
		char c;
		string s;
		cin >> n >> c >> s;
		if (s==string(n, c)) {
			cout << "0\n";
			continue;
		}
		set<int> st;
		for (int i=0; i<n; i++) {
			if (s[i]==c) continue;
			int tmp=i+1;
			for (int j=1; j*j<=i+1; j++) {
				if (tmp%j==0) {
					st.insert(j);	
					st.insert(tmp/j);
				}
			}
		}
		bool flag=false;
		for (int i=2; i<=n; i++) {
			if (st.find(i)==st.end()) {
				cout << 1 << '\n' << i << '\n';
				flag=true;
				break;
			}
		}
		if (flag) continue;
		cout << 2 << '\n';
		cout << n << ' ' << n-1 << '\n';
	}

	return 0;
}
