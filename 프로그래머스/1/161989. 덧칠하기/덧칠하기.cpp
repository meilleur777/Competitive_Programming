#include <bits/stdc++.h>
using namespace std;

int solution(int n, int m, vector<int> section) {
    vector<bool> isPainted(n, true);
    for (auto i:section) isPainted[i-1]=false;
        
    int ret=0;
    for (int i=0; i<n; i++) {
        if (!isPainted[i]) {
            int ptr=i;
            int cnt=0;
            while (ptr<n && cnt<m) {
                isPainted[ptr]=true;
                ptr++;
                cnt++;
            }
            ret++;
        }
    }
    return ret;
}