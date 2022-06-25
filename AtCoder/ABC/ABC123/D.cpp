#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL)
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> intp;

void init_code() {
	fast_io;
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
}

vector<ll> A, B, C;

class cpr {
public:
	bool operator() (const pair<intp, int>& a, const pair<intp, int>& b) {
		return (A[a.first.first]+B[a.first.second]+C[a.second]) <
			   (A[b.first.first]+B[b.first.second]+C[b.second]);
	}
};

int main() {
	init_code();

	int X, Y, Z, K;
	cin >> X >> Y >> Z >> K;
	A.resize(X);
	B.resize(Y);
	C.resize(Z);
	rep(i, X) cin >> A[i];
	rep(i, Y) cin >> B[i];
	rep(i, Z) cin >> C[i];
	sort(A.begin(), A.end(), greater<ll>());
	sort(B.begin(), B.end(), greater<ll>());
	sort(C.begin(), C.end(), greater<ll>());
	priority_queue<pair<ll, vector<int>> > pq;
	int cnt = 1, out = 0;
	pq.push({A[0]+B[0]+C[0], {0, 0, 0}});
	set<vector<int> > vis;
	vis.insert({0, 0, 0});
	while (out < K) {
		int Aptr = pq.top().second[0];
		int Bptr = pq.top().second[1];
		int Cptr = pq.top().second[2];
		cout << A[Aptr]+B[Bptr]+C[Cptr] << '\n';
		pq.pop();
		out++;

		if (Aptr+1 < A.size() && vis.find({Aptr+1, Bptr, Cptr}) == vis.end()) {
			vis.insert({Aptr+1, Bptr, Cptr});
			pq.push({A[Aptr+1]+B[Bptr]+C[Cptr], {Aptr+1, Bptr, Cptr}});
		}
		if (Bptr+1 < B.size() && vis.find({Aptr, Bptr+1, Cptr}) == vis.end()) {
			vis.insert({Aptr, Bptr+1, Cptr});
			pq.push({A[Aptr]+B[Bptr+1]+C[Cptr], {Aptr, Bptr+1, Cptr}});
		}
		if (Cptr+1 < C.size() && vis.find({Aptr, Bptr, Cptr+1}) == vis.end()) {
			vis.insert({Aptr, Bptr, Cptr+1});
			pq.push({A[Aptr]+B[Bptr]+C[Cptr+1], {Aptr, Bptr, Cptr+1}});
		}
	}

	return 0;
}
