#include <iostream>
using namespace std;

/*t^2 + t <= d인 최대 t를 구하라.*/
int solve(int d) {
	int t = 0;
	while (t * (t + 1) <= d) t++;
	return t - 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int T; cin >> T;
	while (T--) {
		int d; cin >> d;
		cout << solve(d) << '\n'; 
	}	
}

