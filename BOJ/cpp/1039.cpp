#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
		
	int k;
	string n;
	cin >> n >> k;

	set<pair<string, int>> st;
	queue<pair<string, int>> q;
	q.push({n, 0});

	int ans=-1;
	while (!q.empty()) {
		string t=q.front().first;
		int cnt=q.front().second;
		q.pop();
		if (cnt==k) {
			ans=max(ans, stoi(t));
			continue;
		}
		for (int i=0; i<(int)t.size(); i++) {
			for (int j=0; j<i; j++) {
				string nxt=t;
				char c=nxt[i];
				nxt[i]=nxt[j];
				nxt[j]=c;
				if (nxt[0]!='0' && st.find({nxt, cnt+1})==st.end()) {
					st.insert({nxt, cnt+1});
					q.push({nxt, cnt+1});
				}
			}
		}
	}
	cout << ans;

	return 0;
}
