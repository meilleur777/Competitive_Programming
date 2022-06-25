#include <stdio.h>
#define NUM 1000000000

/*Dynamic Programming
dp[a][b] -> a번째 숫자가 b로 끝나는 계단 수의 개수
이 시행이 0~9까지 숫자가 한번씩 등장했는지 저장해야 한다.
다시 말해 똑같이 a번째 숫자가 b로 끝날지라도, 0~9까지의 숫자가 모두 나온 경우도 있고,
그렇지 않은 경우도 있을 것이다. bitmask로 dp[a][b][1024]를 이용하여 0~9의 상태를 저장할 수 있다.
(0~9가 모두 등장했다면 1023이 될 것이다) 
*/

long long dp[101][10][1024] = { 0 };

int main() {
	int N; scanf("%d", &N);
	for (int i = 0; i < 10; i++) {
		us x = 0; 
		x |= 1 << i;
		dp[1][i][x] = 1;
	}
	
	for (int i = 2; i <= N; i++) {
		for (int k = 0; k < 1024; k++) {
			dp[i][0][k | 1] += dp[i - 1][1][k] % NUM;
			dp[i][9][k | (1 << 9)] += dp[i - 1][8][k] % NUM;
		}
		
		for (int j = 1; j < 9; j++) {
			for (int k = 0; k < 1024; k++) {
				dp[i][j][k | (1 << j)] += dp[i - 1][j - 1][k] % NUM + dp[i - 1][j + 1][k] % NUM;
			}
		}
	}
	
	long long sum;		
	for (int i = 1; i < 10; i++) sum += dp[N][i][1023] % NUM;
	printf("%lld", sum % NUM);
}

