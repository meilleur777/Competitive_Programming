#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll s, t;
	cin >> s >> t;
	if (s==t) {	
		cout << 0;
		return 0;
	}
	auto comp=[](string a, string b) {
		if (a.size()<b.size()) return a;
		if (a.size()==b.size()) return min(a, b);
		else return b;
	};
	auto sol=[&](int snum, string sstr) {
		set<ll> st;
		queue<pair<ll, string>> q;
		q.push({snum, sstr});
		string ret(100, '/'+1);
		st.insert(snum);
		while (!q.empty()) {
			ll a=q.front().first;
			string str=q.front().second;
			q.pop();
			if (a==t) {
				ret=comp(ret, str);
				continue;
			}
			if (st.find(a*a)==st.end() && a*a<=t) {
				q.push({a*a, str+"*"});
				st.insert(a*a);
			}
			if (st.find(a+a)==st.end() && a+a<=t) {
				q.push({a+a, str+"+"});
				st.insert(a+a);
			}
		}
		return ret;
	};
	string ans=comp(sol(s, ""), sol(1, "/"));
	if (ans[0]==char('/'+1)) cout << -1;
	else cout << ans;

	return 0;
}
