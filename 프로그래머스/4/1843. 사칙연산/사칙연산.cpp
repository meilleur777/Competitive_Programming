#include <bits/stdc++.h>
using namespace std;

//Dynamic Prgramming
int solution(vector<string> arr) {

    int n=((int)arr.size()+1)/2;
    vector<vector<pair<int, int>>> cache(n, 
        vector<pair<int, int>>(n+1, {INT_MAX, INT_MIN}));

    for (int i=0; i<n; i++) {
        int tmp=stoi(arr[i*2]);
        cache[i][1]={tmp, tmp};
    }

    for (int size=2; size<=n; size++) {
        for (int start=0; start<n; start++) {
            if (start*2+size*2-2>=(int)arr.size()) break;

            for (int k=start; k<start+size-1; k++) {
                char tgt=arr[k*2+1][0];
                int leftsize=k-start+1;
                int rightsize=(start+size-1)-(k+1)+1;
                if (tgt=='+') {
                    cache[start][size].first=min(cache[start][size].first,
                        cache[start][leftsize].first+cache[k+1][rightsize].first);
                    cache[start][size].second=max(cache[start][size].second,
                        cache[start][leftsize].second+cache[k+1][rightsize].second);
                }
                else {
                    cache[start][size].first=min(cache[start][size].first,
                        cache[start][leftsize].first-cache[k+1][rightsize].second);
                    cache[start][size].second=max(cache[start][size].second,
                        cache[start][leftsize].second-cache[k+1][rightsize].first);
                }
            }
        }
    }

    return cache[0][n].second;
}
