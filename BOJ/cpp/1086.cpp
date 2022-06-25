#include <stdio.h>
#include <string.h>
typedef long long ll;

/*Dynamic Programming Using Bitmask*/

int N, K;
int ten[52], len[16], mod[16] = { 0 };
ll dp[101][33000];

ll GCD(ll a, ll b) {
	if (!(a % b)) return b;
	else return GCD(b, a % b); 
}

ll rec(int now, int state) {
	if (state == ((1 << N) - 1)) return !now;
	else if (dp[now][state] != -1) return dp[now][state];
	else {
		dp[now][state] = 0;
		for (int i = 0; i < N; i++) {
			if (!(state & (1 << i))) {
				int temp = (now * ten[len[i]] + mod[i]) % K;
				dp[now][state] += rec(temp, state | (1 << i));
			}
		}
		return dp[now][state];
	}
}

int main() {
	scanf("%d", &N);
	ll fac = 1;
	char num[16][52]; 
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++) {
		scanf("%s", num[i]);
		fac *= i + 1;
	} 
	scanf("%d", &K);
	
	for (int i = 0; i < N; i++) {
		len[i] = strlen(num[i]);
		for (int j = 0; j < len[i]; j++) 
			mod[i] = (mod[i] * 10 + (num[i][j] - '0')) % K;
	}
	
	ten[0] = 1 % K;
	for (int i = 1; i < 52; i++) ten[i] = (ten[i - 1] * 10) % K;
	
	ll result = rec(0, 0);
	if (result == fac) printf("1/1\n");
	else if (!result) printf("0/1\n");
	else {
		ll g = GCD(result, fac);
		printf("%lld/%lld\n", result / g, fac / g);
		
	}
}
