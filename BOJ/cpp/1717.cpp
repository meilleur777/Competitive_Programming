#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

const int mod=1e9+7;
const int INF=0x3F3F3F3F;

vector<int> par;

int find(int x) {
	if (x==par[x]) return x;
	return par[x]=find(par[x]);
}

void merge(int a, int b) {
	a=find(a), b=find(b);
	par[a]=b;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	par.resize(n+1);
	rep(i, n+1) par[i]=i;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a) {
			if (find(b)==find(c)) cout << "YES\n";
			else cout << "NO\n";
		}
		else merge(b, c);
	}

	return 0;
}
