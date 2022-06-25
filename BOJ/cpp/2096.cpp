#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
	int N; scanf("%d", &N);
		
	int pMIN[3] = { 0 }, pMAX[3] = { 0 };	
	int MIN[3] = { 0 }, MAX[3] = { 0 };	
	for (int i = 1; i <= N; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		
		MIN[0] = a + min({pMIN[0], pMIN[1]});
		MIN[1] = b + min({pMIN[0], pMIN[1], pMIN[2]});
		MIN[2] = c + min({pMIN[1], pMIN[2]});
		
		MAX[0] = a + max({pMAX[0], pMAX[1]});
		MAX[1] = b + max({pMAX[0], pMAX[1], pMAX[2]});
		MAX[2] = c + max({pMAX[1], pMAX[2]});
		
		for (int j = 0; j < 3; j++) {
			pMIN[j] = MIN[j];
			pMAX[j] = MAX[j];
		}
	}
	
	printf("%d %d", max({pMAX[0], pMAX[1], pMAX[2]}), min({pMIN[0], pMIN[1], pMIN[2]}));
}

