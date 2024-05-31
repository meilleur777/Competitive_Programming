#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	int n=(int)s.size();
	int pcnt=0;
	rep(i, n) pcnt+=(s[i]=='p');
	cout << n/2-pcnt;

	return 0;
}
