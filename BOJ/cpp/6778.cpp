#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	if (a>=3 && b<=4) cout << "TroyMartian\n";
	if (a<=6 && b>=2) cout << "VladSaturnian\n";
	if (a<=2 && b<=3) cout << "GraemeMercurian\n";

	return 0;
}
