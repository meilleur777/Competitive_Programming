#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a+b+c>=100) cout << "OK";
	else {
		int t=min({a, b, c});
		if (t==a) cout << "Soongsil";
		if (t==b) cout << "Korea";
		if (t==c)cout << "Hanyang";
	}


	return 0;
}
