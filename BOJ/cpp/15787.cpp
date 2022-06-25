#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> v(n, 0);
	while (m--) {
		int a, i, x;
		cin >> a >> i;
		int tmp=v[i-1];
		switch (a) {	
			case 1: cin >> x; tmp|=(1<<(x-1)); break;
			case 2: cin >> x; tmp&=~(1<<(x-1)); break;
			case 3: tmp<<=1; break;
			case 4: tmp>>=1; break;
		}
		tmp&=~(1<<20);
		v[i-1]=tmp;
	}
	set<int> st;
	for (int i:v) st.insert(i);
	cout << (int)st.size();

	return 0;
}
