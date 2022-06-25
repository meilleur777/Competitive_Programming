#include <stdio.h>

int main() {
	int i, j, k;
	int N, M, B; //세로, 가로, 블록 개수 
	scanf("%d %d %d", &N, &M, &B);
	
	int height;
	int blockNumber[300] = { 0 }; //어떤 층에 존재하는 블록 수  
	int maxHeight = -1, minHeight = 300;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)  {
			scanf("%d", &height);
			
			if (height < minHeight) minHeight = height;
			else if (height > maxHeight) maxHeight = height;
				
			for (k = 1; k <= height; k++) blockNumber[k]++;
		}
	}
	
	int last = maxHeight + 1;	 
	int time[300] = { 0 };	 
	for (i = minHeight; i <= maxHeight; i++) {		//최고 높이를 i로 만드는  케이스를 점검 
		int Btemp = B;
		
		for (j = minHeight; j < i; j++) {			//최소 높이에서부터 블록을 쌓는다 
			int temp = N * M - blockNumber[j + 1];
			time[i] += temp;
			Btemp -= temp;
		}
		
		for (j = i; j < maxHeight; j++) {				//최고 높이에서부터	깎는다
			time[i] += blockNumber[j + 1] * 2; 			 
			Btemp += blockNumber[j + 1]; 					//깎은 블록은 인벤토리로 
		}
		
		if (Btemp < 0) {		//블록 개수가 모자라면 불가능한 높이이므로 종료 
			last = i;		//last는 최초로 불가능한 높이이다. 
			break;
		}
		
	}
	
	int result = minHeight;
	for (i = minHeight + 1; i < last; i++) 			//최고층의 높이가 minHeight에서 last-1인 
		if (time[result] >= time[i]) result = i;	//케이스 중 하나에 정답이 존재한다 
	printf("%d %d", time[result], result);
	
	return 0;
}
