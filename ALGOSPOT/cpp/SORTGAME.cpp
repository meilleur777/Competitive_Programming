#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

map<vector<int>, int> toSort[9];

void precalc(int n) {
	vector<int> perm(n);
	for (int i=0; i<n; i++) {
		perm[i] = i;
	}
	
	queue<vector<int> > q;
	q.push(perm);
	toSort[n].insert({perm, 0});
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		
		int cost = toSort[n][here];
		for (int i=0; i<n; i++) {
			for (int j=i+2; j<=n; j++) {
				reverse(here.begin()+i, here.begin()+j);
				if (toSort[n].find(here) == toSort[n].end()) {
					toSort[n][here] = cost+1;
					q.push(here);
				}
				reverse(here.begin()+i, here.begin()+j);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i=1; i<=8; i++) {
		precalc(i);
	}
		
	int C;
	cin >> C;
	while (C--) {
		int N;
		cin >> N;
		
		vector<int> A(N), comA(N);		
		for (int i=0; i<N; i++) {
			cin >> A[i];
			comA[i] = A[i];
		}
		sort(comA.begin(), comA.end());
		for (int i=0; i<N; i++) {
			A[i] = lower_bound(comA.begin(), comA.end(), A[i])-comA.begin();
		}
		
		auto res = toSort[N].find(A);
		cout << res->second << '\n';
	}
}

