#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int H, W, N;
	cin >> H >> W >> N;	
	
	vector<int> A(N), B(N), cA(N), cB(N);
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		
		A[i] = a, B[i] = b;
		cA[i] = A[i], cB[i] = B[i];
	}
	
	sort(cA.begin(), cA.end());
	sort(cB.begin(), cB.end());
	cA.erase(unique(cA.begin(), cA.end()), cA.end());
	cB.erase(unique(cB.begin(), cB.end()), cB.end());
	
	for (int i = 0; i < N; i++) {
		int y = lower_bound(cA.begin(), cA.end(), A[i]) - cA.begin();
		int x = lower_bound(cB.begin(), cB.end(), B[i]) - cB.begin();
		
		cout << y + 1 << ' ' << x + 1 << '\n';
	}
}

