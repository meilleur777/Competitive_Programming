#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

/*최소 분할 횟수 구하기
dp[k]을 1~k까지의 최소 분할 횟수라고 할 때 dp[len(A)]을 구해야 한다.
dp[k]는 dp[k - 1] + 1일 수 있다. 또는 A[k]가 펠린드롬 문자열에 포함되어 있다면,
그 펠린드롬 문자열을 포함한 최소 분할 횟수일수도 있다.
따라서 A[k]가 펠린드롬 문자열에 포함된다면 그 펠린드롬 문자열을 포함한 최소 분할 횟수와
dp[k - 1] + 1을 비교한다.*/

bool dp[2510][2510] = { false };

int main() {
	char S[2510], str[2510]; scanf("%s", S);
	int len = strlen(S);
	for (int i = 0; i < len; i++) str[i + 1] = S[i];
	for (int i = 1; i <= len; i++) {
		dp[i][i] = 1;
		int j = 1;
		while (i - j > 0 && i + j <= len) {
			dp[i - j][i + j] = dp[i - j + 1][i + j - 1] && (str[i - j] == str[i + j]);
			if (!dp[i - j][i + j]) break;
			j++;			
		}
	}
	
	for (int i = 1; i < len; i++) dp[i][i + 1] = (str[i] == str[i + 1]);
	
	for (int s = 1, e = 2; e <= len; s++, e++) {
		int j = 1;
		while (s - j > 0 && e + j <= len) {
			dp[s - j][e + j] = dp[s - j + 1][e + j - 1] && (str[s - j] == str[e + j]);
			if (!dp[s - j][e + j]) break;
			j++;
		}
	}
	
	int cnt[2510];
	memset(cnt, 0x7F, sizeof(cnt));
	cnt[0] = 0; 
	for (int i = 1; i <= len; i++) {
		for (int j = 1; j <= i; j++) {
			if (dp[j][i]) cnt[i] = MIN(cnt[i], cnt[j - 1] + 1);
		}
	}
	printf("%d\n", cnt[len]);
}

