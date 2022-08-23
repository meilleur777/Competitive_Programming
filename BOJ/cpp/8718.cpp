#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	ll a, b;
	cin >> a >> b;
    if (7000*b<=1000*a) cout << 7000*b;
    else if (3500*b<=1000*a) cout << 3500*b;
    else if (1750*b<=1000*a) cout << 1750*b;
    else cout << 0;

	return 0;
}
