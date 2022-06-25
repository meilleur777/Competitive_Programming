#include <vector>
#include <iostream>
using namespace std;

vector<int> Postorder, Inorder;

void Preorder(int PostBegin, int PostEnd, int InBegin, int InEnd) {
	if (PostBegin > PostEnd) return;
	cout << Postorder[PostEnd] << ' ';
	for (int i = InBegin; i <= InEnd; i++) {
		if (Inorder[i] == Postorder[PostEnd]) {
			Preorder(PostBegin, i + PostBegin - InBegin - 1, InBegin, i - 1);
			Preorder(i + PostBegin - InBegin, PostEnd - 1, i + 1, InEnd);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int n; cin >> n;
	Postorder.resize(n), Inorder.resize(n);
	for (int i = 0; i < n; i++) cin >> Inorder[i];
	for (int i = 0; i < n; i++) cin >> Postorder[i];
	Preorder(0, n - 1, 0, n - 1);
}

