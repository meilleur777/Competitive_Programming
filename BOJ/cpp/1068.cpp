#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

	int n;
	cin >> n;
    int root;
    vector<vector<int>> child(n);
	for (int i=0; i<n; i++) {
		int x; 
		cin >> x;
		if (x==-1) root=i;
		else child[x].push_back(i);
	}

    int eraseNode;
    cin >> eraseNode;

    if (eraseNode==root) {
        cout << 0;
    }
    else {
        function<int(int)> sol=[&](int now) {

            int ret=0;
            int cnt=0;
            for (auto nxt:child[now]) {
                if (nxt==eraseNode) continue;
                ret+=sol(nxt);
                cnt++;
            }

            if (cnt==0) return 1;
            return ret;
        };
        cout << sol(root);
    }


	return 0;
}
