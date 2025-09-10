#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		function<int()> func=[&]() {
			int point=0;

			for (int i=0; i<3; i++) {
				double a, b;
				cin >> a >> b;
				double dist=(a*a+b*b);

				if (dist<=9) {
					point+=100;
				}
				else if (dist<=6*6) {
					point+=80;
				}
				else if (dist<=9*9) {
					point+=60;
				}
				else if (dist<=12*12) {
					point+=40;
				}
				else if (dist<=15*15) {
					point+=20;
				}
			}

			return point;
		};

		int n=func();
		int m=func();

		cout << "SCORE: " << n << " to " << m << ", ";
		if (n>m) cout << "PLAYER 1 WINS.\n";
		if (n==m) cout << "TIE.\n";
		if (n<m) cout << "PLAYER 2 WINS.\n";
	}

	return 0;
}
