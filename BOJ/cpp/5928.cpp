#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int d, h, m;
	cin >> d >> h >> m;
	int start=11*24*60+11*60+11;
	int end=d*24*60+h*60+m;
	cout << max(-1, end-start);

	return 0;
}
