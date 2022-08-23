#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<int> a(4);
	rep(i, 4) cin >> a[i];

	if (a[0]<a[1] && a[1]<a[2] && a[2]<a[3]) cout << "Fish Rising";
	else if (a[0]>a[1] && a[1]>a[2] && a[2]>a[3]) cout << "Fish Diving";
	else if (a[0]==a[1] && a[1]==a[2] && a[2]==a[3]) cout << "Fish At Constant Depth";
	else cout << "No Fish";

	return 0;
}
