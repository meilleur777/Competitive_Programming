#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<bool>> a(n, vector<bool>(n, false));
	while (m--) {
		int b, c;
		cin >> b >> c;
		b--, c--;
		a[b][c]=true;
		a[c][b]=true;
	}
	set<int> st;
	for (int i=1; i<n; i++) {
		if (a[0][i]) {
			st.insert(i);
			for (int j=1; j<n; j++) {
				if (a[i][j]) {
					st.insert(j);
				}
			}
		}
	}
	cout << (int)st.size();

	return 0;
}
