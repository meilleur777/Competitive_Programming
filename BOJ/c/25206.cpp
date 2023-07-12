#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
		
	ld sum=0;
	ld sum2=0;
	map<string, ld> mp;
	mp["A+"]=4.5;
	mp["A0"]= 4.0;
	mp["B+"]= 	3.5;
	mp["B0"]= 	3.0;
	mp["C+"]= 	2.5;
	mp["C0"]= 	2.0;
	mp["D+"]= 	1.5;
	mp["D0"]= 	1.0;
	mp["F"]=	0.0;
	for (int i=0; i<20; i++) {
		string s;
		ld a;
		string b;
		cin >> s >> a >> b;
		if (b=="P") continue;
		sum+=mp[b]*a;
		sum2+=a;
	}
	cout << fixed;
	cout.precision(10);
	cout << sum/sum2;

	return 0;
}
