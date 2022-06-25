#include <stdio.h>

/*postorder의 가장 오른쪽 출력은 부모노드이다. 
Inorder의 부모노드를 기준으로 왼쪽 트리와 오른쪽 트리가 나뉜다.
Inorder를 인덱싱하여 재귀적으로 왼쪽 트리와 오른쪽 트리에 대해서도 같은 방식으로
루트를 발견할 수 있다.*/

int Postorder[100001];
int Inorder[100001];

void rec(int Ins, int Ine, int Pos, int Poe) {
	if (Ins > Ine || Pos > Poe) return;
	if (Ins == Ine) {
		printf("%d ", Inorder[Ine]);
		return;
	}
	printf("%d ", Postorder[Poe]);
	for (int i = Ins; i <= Ine; i++) {
		if (Inorder[i] == Postorder[Poe]) {
			rec(Ins, i - 1, Pos, i - 1 - Ins + Pos);
			rec(i + 1, Ine, i - Ins + Pos, Poe - 1);
		}
	}
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &Inorder[i]); 
	for (int i = 0; i < n; i++) scanf("%d", &Postorder[i]);
	rec(0, n - 1, 0, n - 1);	
}

