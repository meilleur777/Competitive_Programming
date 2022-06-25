#include <iostream>
#define NUM 1000000001
using namespace std;

int length[51];

char solve(const string& seed, int generations, int skip) {
	if (!generations) return seed[skip];
	
	for (int i = 0; i < seed.size(); i++) {
		bool A = seed[i] == 'X', B = seed[i] == 'Y';
		bool C = skip >= length[generations];
		
		if ((A || B) && C) skip -= length[generations];
		else if (A) return solve("X+YF", generations - 1, skip);
		else if (B) return solve("FX-Y", generations - 1, skip);
		else if (skip > 0) skip--;
		else return seed[i];
	}
}

void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; i++) length[i] = min(NUM, length[i - 1] * 2 + 2);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	precalc();
	
	int C; cin >> C;
	while (C--) {
		int n, p, l;
		cin >> n >> p >> l;
		for (int skip = p - 1; skip < p + l - 1; skip++) cout << solve("FX", n, skip);
		cout << '\n';
	}	
}

