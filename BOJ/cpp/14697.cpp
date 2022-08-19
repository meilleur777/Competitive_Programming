#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c, n;
	cin >> a >> b >> c >> n;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			for (int k=0; k<=n; k++) {
				if (a*i+j*b+k*c==n) {
					cout << 1;
					return 0;
				}
			}
		}
	}
	cout << 0;

	return 0;
}
