#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int a, b, c;
	cin >> a >> b >> c;
	cout << (a+1)*(b+1)/(c+1)-1;

	return 0;
}
