#include <bits/stdc++.h>
using namespace std;

/*here --edge--> return*/
int append(int here, int edge, int mod) {
	int there = here*10+edge;
	if (there >= mod) return mod+there%mod;
	return there%mod;
}

/*find minimal C such that C%n=m, C>=n+m*/
string solve(string& d, int n, int m) {
	sort(d.begin(), d.end());
	
	vector<int> parent(2*n, -1), choice(2*n, -1);
	queue<int> q;
	parent[0] = 0;
	q.push(0);
	
	while (!q.empty()) {
		int here = q.front();
		q.pop();
		
		for (int i=0; i<d.size(); i++) {
			int there = append(here, d[i]-'0', n);
			if (parent[there] == -1) {
				parent[there] = here;
				choice[there] = d[i]-'0';
				q.push(there);
			}
		}
	}
	
	if (parent[n+m] == -1) {
		return "IMPOSSIBLE";
	}
	
	string ret;
	int here = n+m;
	while (parent[here] != here) {
		ret.push_back(char(choice[here]+'0'));
		here = parent[here];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		string d;
		cin >> d;
		
		int N, M;
		cin >> N >> M;
				
		cout << solve(d, N, M) << '\n';
	}
}

