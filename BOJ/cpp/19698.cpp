#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n, w, h, l;
	cin >> n >> w >> h >> l;
	cout << min((w/l)*(h/l), n);

	return 0;
}
