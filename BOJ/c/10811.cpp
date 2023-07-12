#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int n, m;
	cin >> n >> m;
	vector<int> ball(n);
	for (int i=0; i<n; i++) {
		ball[i]=i+1;
	}
	while (m--) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		for (int i=0; i<(b-a+1)/2; i++) {
			int t=ball[a+i];
			ball[a+i]=ball[b-i];
			ball[b-i]=t;
		}
	} 
	for (int i=0; i<n; i++) {
		cout << ball[i] << ' ';
	}

	return 0;
}
