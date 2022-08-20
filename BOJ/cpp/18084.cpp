#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	vector<string> s(5);
	rep(i, 5) cin >> s[i];

	vector<int> a(4);
	rep(i, 5) s[i].erase(find(s[i].begin(), s[i].end(), '.'));
	rep(i, 4) {
		a[i]=stoi(s[i]);
	}
	int n=stoi(s[4]);

	int left=0, right=10000;
	int ans=-1;
	while (left<=right) {
		int mid=(left+right)/2;
		vector<int> b=a;
		b.push_back(mid);
		sort(b.begin(), b.end());
		int tmp=b[1]+b[2]+b[3];
		if (tmp>n*3) {
			right=mid-1;
		}
		else {
			left=mid+1;
			ans=max(ans, mid);
		}
	}
	if (ans<=0) cout << "impossible";
	else if (ans==10000) cout << "infinite";
	else {
		string s=to_string(ans);
		while ((int)s.size()<4) s='0'+s;
		s=s.substr(0, 2)+'.'+s.substr(2);
		if (s[0]=='0') s=s.substr(1);
		cout << s;
	}

	return 0;
}
