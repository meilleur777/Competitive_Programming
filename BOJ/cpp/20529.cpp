#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<string> v(n);
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		int ans=100;
		if (n<48) {
			for (int i=0; i<n; i++) {
				for (int j=i+1; j<n; j++) {
					for (int k=j+1; k<n; k++) {
						int tmp=0;
						for (int l=0; l<4; l++) {
							tmp+=v[i][l]!=v[j][l];
							tmp+=v[j][l]!=v[k][l];
							tmp+=v[k][l]!=v[i][l];
						}
						ans=min(ans, tmp);
					}
				}
			}
		}
		else ans=0;
		cout << ans << '\n';
	}

	return 0;
}
