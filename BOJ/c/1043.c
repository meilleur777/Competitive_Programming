#include <stdio.h>

int pos[51] = { 0 }; /*pow[k] = 1 -> 진실, 0 -> 거짓*/ 
int num[51] = { 0 }; /*num[k] = k가 속한 파티 수*/
int party[51][51] = { 0 }; /*party[k]는 k라는 구성원이 속한 파티의 목록*/
int pnum[51] = { 0 }; /*pnum[k]는 k번 파티의 구성원 숫자*/
int other[51][51] = { 0 }; /*other[k]는 k번 파티에 속한 구성원의 목록*/
int know[51] = { 0 }; /*구성원 k가 진실을 말해야 하는 사람이면 know[k] = 1*/

/*어떤 파티의 한 구성원이 진실을 알고 있다면, 그 파티에서는 진실을 말해야 하므로,
그 파티의 구성원 모두 진실을 아는 사람으로 취급된다. 따라서 그 파티의 구성원이 속한
다른 파티 또한 진실을 말해야 하는 파티가 된다. dfs를 이용해 진실을 전염시키고,
전염되지 않은 파티의 수가 거짓말을 할 수 있는 횟수이다.*/

void DFS(int V) {
	for (int i = 0; i < num[V]; i++) {
		/*V가 속한 i번째 파티는 이제 진실 파티가 되었다.*/
		if (!pos[party[V][i]]) {
			pos[party[V][i]] = 1;
			/*이 파티의 구성원 중 진실을 모르던 사람을 진실을 아는 사람으로 바꾸고,
			그 사람이 속한 파티에 대해서 같은 방법으로 진행한다.*/
			for (int j = 0; j < pnum[party[V][i]]; j++) {
				if (!know[other[party[V][i]][j]]) {
					know[other[party[V][i]][j]] = 1;
				}			
				DFS(other[party[V][i]][j]);
			}
		}
	}
}

int main() {
	int N, M; scanf("%d %d", &N, &M);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		know[x] = 1;
	} 
	
	/*파티의 번호는 1 ~ M으로 설정*/
	for (int i = 1; i <= M; i++) {
		scanf("%d", &pnum[i]);
		
		/*i번째 파티에 속한 구성원을 입력받는다*/
		for (int j = 0; j < pnum[i]; j++) { 
			int a; scanf("%d", &a);
			other[i][j] = a;
			party[a][num[a]++] = i; 
		}
	}
	int count = 0;
	for (int i = 1; i <= N; i++) if (know[i]) DFS(i);
	for (int i = 1; i <= M; i++) if (!pos[i]) count++;
	printf("%d\n", count);
}

