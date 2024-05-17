#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> sushi(n);
    for (int i=0; i<n; i++) {
        cin >> sushi[i];
    }

    int start=0;
    int end=0;
    int nowSize=0;
    int ans=0;
    map<int, int> cntSushi;
    while (start<n) {
        while (nowSize<k) {
            cntSushi[sushi[end%n]]++;
            end++;
            nowSize++;
        }

        int add=0;
        if (cntSushi.find(c)==cntSushi.end()) {
            add=1;
        }
        ans=max(ans, (int)cntSushi.size()+add);

        cntSushi[sushi[start]]--;
        if (cntSushi[sushi[start]]==0) {
            cntSushi.erase(sushi[start]);
        }
        start++;
        nowSize--;
    }

    cout << ans;

    return 0;
}
