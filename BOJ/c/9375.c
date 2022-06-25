#include <stdio.h>
#include <string.h>

int main() {
	int i, j, k, T, n;
	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		int arr[31] = { 0 }, result = 1;	
		char kinds[31][21], name[21], kind[21]; 		
		int numberOfKinds = 0;
		
		scanf("%d", &n);
		for (j = 0; j < n; j++) {
			scanf("%s %s", name, kind);
			
			k = 0;
			while (strcmp(kind, kinds[k])) {
				if (k == numberOfKinds) {
					strcpy(kinds[k], kind);
					numberOfKinds++;
					break;
				}
				k++;
			}
			arr[k]++;
		}
		
		for (j = 0; j < numberOfKinds; j++) result *= arr[j] + 1;
			
		printf("%d\n", result - 1);
	}
	
	return 0;
}
