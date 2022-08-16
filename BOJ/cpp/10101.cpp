#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b, c;
	cin >> a >> b >> c;
	if (a+b+c!=180) cout << "Error";
	else {
		if (a==b && b==c && c==a) cout << "Equilateral";
		else if ((a==b && b!=c) || (b==c && b!=a) || (a==c && b!=c)) cout << "Isosceles";
		else if (a!=b && b!=c && a!=c) cout << "Scalene";
	}

	return 0;
}
