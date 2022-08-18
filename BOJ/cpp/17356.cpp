#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cout << fixed;
	cout.precision(5);

	int a, b;
	cin >> a >> b;
	cout << (ld)1/((ld)1+pow(10, (ld)(b-a)/400));

	return 0;
}
