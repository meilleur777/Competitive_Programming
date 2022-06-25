#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;
	set<string> st;
	vector<pair<string, intp>> v;
	map<string, vector<int>> mp;
	int mx=-1;
	rep(i, n) {
		string name, place;
		intp time;
		cin >> name >> place >> time.first >> time.second;
		if (st.find(name)!=st.end()) continue;
		v.push_back({place, time});
		st.insert(name);
		if (mp.find(place)==mp.end()) {
			mp[place]=vector<int>(50001, 0);
		}
		for (int i=time.first; i<time.second; i++) {
			mp[place][i]++;
			mx=max(mx, mp[place][i]);
		}
	}
	string anss;
	int anssta=-1, ansed=-1;
	bool flag=false;
	for (auto [a, b]:mp) {
		int now=0;
		int sta=-1;
		if (flag) break;
		for (int i=0; i<50001; i++) {
			if (mx==b[i]) {
				if (sta==-1) sta=i;
				flag=true;
				anss=a;
				anssta=sta, ansed=i+1;	
			}
			else {
				if (flag) break;
				sta=-1, now=0;
			}
		}
	}
	cout << anss << ' ' << anssta << ' ' << ansed;


	return 0;
}
