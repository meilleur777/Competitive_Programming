#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int x;
	while (cin >> x) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];

		x*=1e7;
		sort(a.begin(), a.end());
		bool flag=false;
		for (int left=0; left<n-1; left++) {
			auto upp=upper_bound(a.begin()+left+1, a.end(), x-a[left]);
			auto low=lower_bound(a.begin()+left+1, a.end(), x-a[left]);
			if (upp-low+1>1) {
				flag=true;
				cout << "yes " << a[left] << ' ' << x-a[left] << '\n';
				break;
			}
		}
		if (!flag) cout << "danger\n";
	}	

	return 0;
}
