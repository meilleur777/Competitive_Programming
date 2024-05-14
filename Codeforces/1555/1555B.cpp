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
	cout << fixed;
	cout.precision(10);
	
	int T;
	cin >> T;
	while (T--) {
		int W, H;
		cin >> W >> H;
		
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		int w, h;
		cin >> w >> h;
		
		if (x2 - x1 + w > W && y2 - y1 + h > H) {
			cout << "-1\n";
			continue;
		}
			
		double ans = 987654321.0;
		if (x2 - x1 + w <= W) {
			ans = min(ans, (double)max(0, w - x1));
			ans = min(ans, (double)max(0, x2 - (W - w)));
		} 
		if (y2 - y1 + h <= H) {
			ans = min(ans, (double)max(0, h - y1));
			ans = min(ans, (double)max(0, y2 - (H - h)));
		}
		cout << ans << '\n';
	}	
}

