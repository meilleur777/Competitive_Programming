#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int sum = 0;
	vector<int> A(5);	
	for (int i = 0; i < 5; i++) {
		cin >> A[i];
		sum += A[i];
	}	
	sort(A.begin(), A.end());
	
	cout << sum / 5 << '\n' << A[2] << '\n';
}

