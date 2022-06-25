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
	
	int T;
	cin >> T;
	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;
		
		int r = abs(a - b);
		
		int range = 2 * r;
		int cand1 = r + c;
		int cand2 = c - r;
		
		//cout << range << '\n';
		//cout << cand1 << ' ' << cand2 << '\n';
 		
 		if (c > range) {
 			cout << "-1\n";
 			continue;
		}
		
		 
		if (a > r && b > r) {
			cout << "-1\n";
			continue;
		} 
		 
		bool A = (cand1 <= range) && (cand1 > 0) && (cand1 != a) && (cand1 != b);
		bool B = (cand2 <= range) && (cand2 > 0) && (cand2 != a) && (cand2 != b);
		
		//cout << A << ' ' << B << '\n';
		
		if (A && B) cout << cand1 << '\n';
		else if (A && !B) {
			cout << cand1 << '\n';
		}
		else if (!A && B) {
			cout << cand2 << '\n';
		}
		else {
			cout << "-1\n";
		}
	}	
}

