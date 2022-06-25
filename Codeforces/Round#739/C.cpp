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
	
		int k;
		cin >> k;
		
		int n = 1;
		while ((int)pow(n - 1, 2) + 1 <= k) {
			n++;
		}
		n--;
		
			
		int row = 0, col = 0;
		int temp = ((int)pow(n - 1, 2) + 1 + n * n)	/ 2;
		int flag = temp;
		if (k > flag) {
			row += n;	
			col += n * n - k + 1;				
		}	
		else {	
			row += k - ((int)pow(n - 1, 2) + 1) + 1;
			col += n;	
		}
		
		cout << row << ' ' << col << '\n';
	}	
}

