#include <vector>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int S[200002] = { 0 }, T[200002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 1; i <= N; i++) {
		cin >> S[i];
	}	
	int minIndex, minValue = INT_MAX;
	for (int i = 1; i <= N; i++) {
		cin >> T[i];
		if (T[i] < minValue) {
			minIndex = i;
			minValue = T[i];
		}
	}
	
	int get[200002];
	get[minIndex] = minValue;
	for (int i = minIndex + 1; i <= N; i++) {
		get[i] = min(get[i - 1] + S[i - 1], T[i]);  
		
	}
	
	for (int i = 1; i < minIndex; i++) {
		if (i == 1) {
			get[i] = min(get[N] + S[N], T[i]);
		}
		else get[i] = min(get[i - 1] + S[i - 1], T[i]);  
	}
	
	for (int i = 1; i <= N; i++) {
		cout << get[i] << '\n';
	}	
	
}

