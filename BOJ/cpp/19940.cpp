#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> p;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int T;
	cin >> T;
	while (T--) {
		int N;
		cin >> N;
		
		int A[5] = { 0 };
		
		A[0] += N/60;
		if (N%60 > 35) {
			N -= (A[0]+1)*60;			
			A[0]++;
		}
		else {
			N -= A[0]*60;
		}
		
		int m;
		if (N > 0) {
			A[1] += N/10;
			if (N%10>5) {
				N -= (A[1]+1)*10;
				A[1]++;
			}
			else {
				N -= A[1]*10;
			}
		}	
		else if (N < 0) {
			A[2] += -N/10;
			if (-N%10>5) {
				N += (A[2]+1)*10;
				A[2]++;
			}
			else {
				N += A[2]*10;
			}
		}	
		
		if (N > 0) {
			A[3] += N;
		}	
		else if (N < 0) {
			A[4] += -N;
		}
		
		for (int i=0; i<5; i++) {
			cout << A[i] << ' ';
		}
		cout << '\n';
	}
}

