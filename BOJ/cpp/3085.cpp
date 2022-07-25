#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); i++)
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];

	int ans=1;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++) {
			if (a[i][j]==a[i][j+1]) continue;
			vector<string> b=a;
			char t=b[i][j];
			b[i][j]=b[i][j+1];
			b[i][j+1]=t;

			int tmp=0;
			for (int k=0; k<n; k++) {
				int now=1;
				for (int l=1; l<n; l++) {
					if (b[k][l]==b[k][l-1]) now++;
					else {
						now=1;
					}
					tmp=max(tmp, now);
				}
			}
			for (int k=0; k<n; k++) {
				int now=1;
				for (int l=1; l<n; l++) {
					if (b[l][k]==b[l-1][k]) now++;
					else {
						now=1;
					}
					tmp=max(tmp, now);
				}
			}
			ans=max(ans, tmp);
		}
	}

	for (int i=0; i<n; i++) {
		for (int j=0; j<n-1; j++) {
			if (a[j][i]==a[j+1][i]) continue;
			vector<string> b=a;
			char t=b[j][i];
			b[j][i]=b[j+1][i];
			b[j+1][i]=t;

			int tmp=1;
			for (int k=0; k<n; k++) {
				int now=1;
				for (int l=1; l<n; l++) {
					if (b[k][l]==b[k][l-1]) now++;
					else {
						now=1;
					}
					tmp=max(tmp, now);
				}
			}
			for (int k=0; k<n; k++) {
				int now=1;
				for (int l=1; l<n; l++) {
					if (b[l][k]==b[l-1][k]) now++;
					else {
						now=1;
					}
					tmp=max(tmp, now);
				}
			}
			ans=max(ans, tmp);
		}
	}

	cout << ans;	

	return 0;
}
