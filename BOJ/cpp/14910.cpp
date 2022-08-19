#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> a;
	int n;
	while (cin >> n) {
		a.push_back(n);
	}
	for (int i=0; i<(int)a.size()-1; i++) {
		if (a[i]>a[i+1]) {
			cout << "Bad";
			return 0;
		}
	}
	cout << "Good";

	return 0;
}
