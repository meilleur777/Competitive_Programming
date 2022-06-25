#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> intp;

vector<int> fib(31);

void precalc() {
	fib[0] = 0, fib[1] = 1;
	
	for (int i = 2; i < fib.size(); i++) {
		fib[i] = fib[i - 1] + fib[i - 2];	
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	precalc();	
	
	int D, K;
	cin >> D >> K;
	
	int A, B;
	for (A = 1; A <= 50000; A++) {
		for (B = A; B <= 50000; B++) {
			int temp = fib[D - 2] * A + fib[D - 1] * B;
			if (temp == K) {
				cout << A << '\n' << B;
				return 0; 
			}
			else if (temp > K) {
				break;
			}
		}
	}
}

