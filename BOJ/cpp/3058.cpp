#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		vector<int> a;
		rep(i, 7) {
			int b;
			cin >> b;
			if (b%2==0) a.push_back(b);
		}
		int sum=0;
		for (auto i:a) sum+=i;
		cout << sum << ' ' << *min_element(a.begin(), a.end()) << '\n';
	}

	return 0;
}
