#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int tc;
	cin >> tc;
	for (int tcn=1; tcn<=tc; tcn++) {
		cout << "Case " << tcn << ":\n";

		int p;
		cin >> p;
		map<string, vector<long long >> mp;
		map<string, int> nameToNum;
		map<int, string> numToName;
		for (int i=0; i<p; i++) {
			string name;
			int x, y, z;
			cin >> name >> x >> y >> z;

			mp[name]={x, y, z};
			nameToNum[name]=i;
			numToName[i]=name;
		}

		vector<vector<long double>> dist(p, vector<long double>(p, 1e18));
		for (int i=0; i<p; i++) {
			dist[i][i]=0;
		}
		for (int i=0; i<p; i++) {
			for (int j=0; j<p; j++) {
				if (i==j) continue;

				dist[i][j]=sqrtl((mp[numToName[i]][0]-mp[numToName[j]][0])*(mp[numToName[i]][0]-mp[numToName[j]][0])
							+(mp[numToName[i]][1]-mp[numToName[j]][1])*(mp[numToName[i]][1]-mp[numToName[j]][1])
							+(mp[numToName[i]][2]-mp[numToName[j]][2])*(mp[numToName[i]][2]-mp[numToName[j]][2]));
			}
		}

		int w;
		cin >> w;
		for (int i=0; i<w; i++) {
			string a, b;
			cin >> a >> b;

			dist[nameToNum[a]][nameToNum[b]]=0;
		}
		
		for (int i=0; i<p; i++) {
			for (int j=0; j<p; j++) {
				for (int k=0; k<p; k++) {
					if (j==k) continue;

					if (dist[j][k]>dist[j][i]+dist[i][k]) {
						dist[j][k]=dist[j][i]+dist[i][k];
					}
				}
			}
		}

		int q;
		cin >> q;
		while (q--) {
			string a, b;
			cin >> a >> b;

			cout << "The distance from " << a << " to " << b << " is ";
			cout << int(dist[nameToNum[a]][nameToNum[b]]+0.5) << " parsecs.\n";
		}
	}

	return 0;
}
