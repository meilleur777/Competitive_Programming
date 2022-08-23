#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	n+=3071;
	string ans;
	ans+=(n/4096+234);
	ans+=(n/64%64+128);
	ans+=(n%64+128);
	cout << ans;
	
	return 0;
}
