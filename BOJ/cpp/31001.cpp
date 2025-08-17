#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	long long n, m, q;
	cin >> n >> m >> q;

  	map<string, long long> frm;
    map<long long, vector<string>> grp;

	while (n--) {
		long long g, p;
		string h; 
		cin >> g >> h >> p;

		frm[h]=p;
		grp[g].push_back(h);
	}

  	map<string, long long> mine;

	while (q--) {
		long long ord;
		cin >> ord;

		if (ord==1) {
			string a;
			long long b;
			cin >> a >> b;

			if (m<frm[a]*b) continue;
			m-=frm[a]*b;
			mine[a]+=b;
		}
		if (ord==2) {
			string a;
			long long b;
			cin >> a >> b;

			long long tmp=min(mine[a], b);
			mine[a]-=tmp;
			m+=frm[a]*tmp;
		}
		if (ord==3) {
			string a;
			long long c;
			cin >> a >> c;

			frm[a]+=c;
		}
		if (ord==4) {
			long long d, c;
			cin >> d >> c;

			for (auto &i : grp[d]) {
				frm[i]+=c;
			}
		}
		if (ord==5) {
			long long d, e;
			cin >> d >> e;

			for (auto &i : grp[d]) {
				frm[i]=frm[i]*(100+e)/100;
				frm[i]-=frm[i]%10;
			}
		}
		if (ord==6) {
			cout << m << '\n';
		}
		if (ord==7) {
			long long res=m;
			for (auto &i : mine) {
				res+=frm[i.first]*i.second;
			}

			cout << res << '\n';
		}
	}

	return 0;
}
