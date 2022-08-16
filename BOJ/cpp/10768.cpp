#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int a, b;
	cin >> a >> b;
	if (a==2 && b==18) cout << "Special";
	if (a<2 || (a==2 && b<18)) cout << "Before";
	else if (a>2 || (a==2 && b> 18)) cout << "After";

	return 0;
}
