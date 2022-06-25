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

	while (true) {
		int n;
		cin >> n;
		if (n==-1) break;
		vector<int> div;
		int sum=1;
		div.push_back(1);
		for (int i=2; i*i<n; i++) {
			if (n%i==0) {
				div.push_back(i);
				div.push_back(n/i);
				sum+=i+n/i;
			}
		}
		int tmp=(int)sqrt(n);
		if (tmp*tmp==n) {
			div.push_back(tmp);
			sum+=tmp;
		}
		if (sum==n) {
			sort(div.begin(), div.end());
			cout << n << " = ";
			for (int i=0; i<(int)div.size()-1; i++) {
				cout << div[i] << " + ";
			}
			cout << *div.rbegin() << '\n';
		}
		else {
			cout << n << " is NOT perfect.\n";
		}
	}	

	return 0;
}
