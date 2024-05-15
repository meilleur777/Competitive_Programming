#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<int> p(m);
    for (int i=0; i<m; i++) cin >> p[i];
    sort(p.begin(), p.end());

    int price=0;
    int profit=0;
    for (int i=0; i<m; i++) {
        int tmpProfit=min((m-i), n)*p[i];
        if (tmpProfit>profit) {
            price=p[i];
            profit=tmpProfit;
        }
    }

    cout << price << ' ' << profit;

    return 0;
}
