#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	set<int> st;
	vector<vector<int>> v(n, vector<int>(n));
	rep(i, n) rep(j, n) {
		cin >> v[i][j];
		st.insert(v[i][j]);
	}
	auto kkk=[]() {
		cout << "FALSE";
		exit(0);
	};
	if ((int)st.size()!=n*n) kkk();
	int t=n*(n*n+1)/2;
	rep(i, n) {
		int row=0, col=0;
		rep(j, n) {
			row+=v[j][i];
			col+=v[i][j];
		}
		if (row!=t || col!=t) kkk();
	}
	int a=0, b=0;
	rep(i, n) {
		a+=v[i][i];
		b+=v[i][n-i-1];
	}
	if (a!=t || b!=t) kkk();
	cout << "TRUE";

	return 0;
}
